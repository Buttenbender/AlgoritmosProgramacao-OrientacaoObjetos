#include "TelaJogo.h"

TelaJogo::TelaJogo() {
    srand(time(0));
}

bool TelaJogo::carregarHistoria(const string& caminhoArquivo) {
    ifstream arquivo(caminhoArquivo);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir arquivo de história: " << caminhoArquivo << endl;
        return false;
    }

    cenas.clear();
    string linha;
    Cena cenaAtual;
    bool lendoCena = false;

    while (getline(arquivo, linha)) {
        if (linha.empty() || (linha.size() >= 2 && linha.substr(0, 2) == "//")) {
            continue;
        }

        if (linha[0] == '#') {
            if (lendoCena) {
                cenas.push_back(cenaAtual);
                cenaAtual = Cena();
            }
            try {
                cenaAtual.id = stoi(linha.substr(1));
                lendoCena = true;
            }
            catch (const invalid_argument& e) {
                cerr << "Erro: ID de cena inválido na linha: " << linha << endl;
                continue;
            }
        }
        else if (linha[0] == '>') {
            size_t separador = linha.find('|');
            if (separador != string::npos) {
                string texto = linha.substr(1, separador - 1);
                try {
                    int destino = stoi(linha.substr(separador + 1));
                    cenaAtual.opcoes.push_back({texto, destino});
                }
                catch (const invalid_argument& e) {
                    cerr << "Erro: Destino inválido na opção: " << linha << endl;
                    continue;
                }
            }
        }
        else if (linha[0] == '@') {
            cenaAtual.evento = linha.substr(1);
            cenaAtual.evento.erase(remove_if(cenaAtual.evento.begin(), cenaAtual.evento.end(), ::isspace), cenaAtual.evento.end());
        }
        else {
            cenaAtual.texto += linha + "\n";
        }
    }

    if (lendoCena) {
        cenas.push_back(cenaAtual);
    }

    arquivo.close();
    return true;
}

void TelaJogo::iniciarHistoria(Personagem* personagem) {
    if (cenas.empty()) {
        cout << "Nenhuma história carregada!\n" << endl;
        return;
    }

    cenaAtual = personagem->getLugarHistoria();
    while (cenaAtual != -1 && cenaAtual < static_cast<int>(cenas.size())) {
        Cena& cena = cenas[cenaAtual - 1];
        cout << "\n" << cena.texto << endl;

        if (!cena.evento.empty()) {
            int novaCena = -1;
            bool eventoProcessado = processarEvento(cena.evento, personagem, novaCena);

            if (eventoProcessado && novaCena != -1) {
                cenaAtual = novaCena;
                continue;
            }
        }

        if (!cena.opcoes.empty()) {
            cout << "--- O que você faz? ---" << endl;
            for (size_t i = 0; i < cena.opcoes.size(); i++) {
                cout << i + 1 << ") " << cena.opcoes[i].texto << endl;
            }
            cout << "0) Sair e Salvar" << endl;

            int escolha;
            cout << "\nEscolha: ";
            cin >> escolha;

            if (escolha > 0 && escolha <= static_cast<int>(cena.opcoes.size())) {
                cenaAtual = cena.opcoes[escolha - 1].destino;
            }
            else if (escolha == 0) {
                personagem->setLugarHistoria(cenaAtual);
                salvarPersonagem("personagem.txt", personagem);
                cenaAtual = -1;
            }
            else {
                cout << "Escolha inválida! Tente novamente!" << endl;
            }
        }
        else {
            cenaAtual = -1;
        }
    }

    cout << "\nFim da História!\n" << endl;
}

bool TelaJogo::processarEvento(const string& evento, Personagem* personagem, int& novaCena) {
    novaCena = -1;

    if (evento == "combate_zumbi") {
        Monstro* zumbi = new Monstro("Zumbi guarda", 0, 5, 10, 5, 2);
        zumbi->adicionarItem(Item("Espada Enferrujada", "arma", 1, 1, 1, 1));
        TelaCombate tc;
        tc.comecarCombate(personagem, zumbi);

        if (personagem->getEnergia() <= 0) {
            cout << "Tente novamente!" << endl;
        }
        else if (zumbi->getEnergia() <= 0) {
            personagem->setTesouro(personagem->getTesouro() + 2);
            cout << "+ 2 moedas de ouro" << endl;
            novaCena = 7;
        }
        else {
            novaCena = 7;
        }

        delete zumbi;
        return true;
    }
    else if (evento == "combate_zumbi_surpresa") {
        Monstro* zumbi = new Monstro("Zumbi Guarda (Surpreso)", 0, 5, 8, 5, 2);
        zumbi->adicionarItem(Item("Espada Enferrujada", "arma", 1, 1, 1, 1));
        TelaCombate tc;
        tc.comecarCombate(personagem, zumbi);

        if (personagem->getEnergia() <= 0) {
            cout << "Tente novamente!" << endl;
        }
        else if (zumbi->getEnergia() <= 0) {
            personagem->setTesouro(personagem->getTesouro() + 2);
            cout << "+ 2 moedas de ouro" << endl;
            novaCena = 7;
        }
        else {
            novaCena = 7;
        }

        delete zumbi;
        return true;
    }
    else if (evento == "sorte_passar_zumbi") {
        char rolar;
        cout << "Digite 's' para rolar a sorte: ";
        cin >> rolar;

        if (rolar == 's' || rolar == 'S') {
            int sorte = 1 + rand() % 12;
            if (sorte <= personagem->getSorte()) {
                cout << "Você teve sorte (" << sorte << ") e passou pelo zumbi sem ser notado!" << endl;
                novaCena = 7;
                return true;
            }
            else {
                cout << "Você falhou no teste de sorte (" << sorte << ")! o zumbi te viu!" << endl;
                Monstro* zumbi = new Monstro("Zumbi guarda", 0, 5, 10, 5, 2);
                zumbi->adicionarItem(Item("Espada Enferrujada", "arma", 1, 1, 1, 1));
                TelaCombate tc;
                tc.comecarCombate(personagem, zumbi);

                if (personagem->getEnergia() <= 0) {
                    cout << "Tente novamente!" << endl;
                }
                else if (zumbi->getEnergia() <= 0) {
                    personagem->setTesouro(personagem->getTesouro() + 2);
                    cout << "+ 2 moedas de ouro" << endl;
                    novaCena = 7;
                }
                else {
                    novaCena = 7;
                }

                delete zumbi;
                return true;
            }
        }
    }
    else if (evento == "pegar_armadura") {
        personagem->adicionarItem(Item("Armadura de Corrente", "armadura", 0, 1, 2, 1));
        cout << "Você encontrou uma Armadura de Corrente! Use o inventário durante uma batalha para equipá-la!" << endl;
        cout << "Você segue adiante. O corredor leva a uma escada que sobe para um pátio. Você percebe que você está em um castelo." << endl;
        novaCena = 10;
        return true;
    }
    else if (evento == "sorte_passar_orc") {
        char rolar;
        cout << "Digite 's' para rolar a sorte: ";
        cin >> rolar;

        if (rolar == 's' || rolar == 'S') {
            int sorte = 1 + rand() % 12;
            if (sorte <= personagem->getSorte()) {
                cout << "Você teve sorte (" << sorte << ") e passou pelo Orc sem ser notado!" << endl;
                novaCena = 13;
                return true;
            }
            else {
                cout << "Você falhou no teste de sorte (" << sorte << ")! O Orc te viu!" << endl;
                Monstro* orc = new Monstro("Orc Guardião", 0, 6, 14, 4, 5);
                orc->adicionarItem(Item("Machado de Batalha", "arma", 1, 1, 3, 3));
                TelaCombate tc;
                tc.comecarCombate(personagem, orc);

                if (personagem->getEnergia() <= 0) {
                    cout << "Tente novamente!" << endl;
                }
                else if (orc->getEnergia() <= 0) {
                    personagem->setTesouro(personagem->getTesouro() + 5);
                    cout << "+ 5 moedas de ouro" << endl;
                    novaCena = 13;
                }
                else {
                    novaCena = 13;
                }

                delete orc;
                return true;
            }
        }
    }
    else if (evento == "combate_orc") {
        Monstro* orc = new Monstro("Orc Guardião", 0, 6, 14, 4, 5);
        orc->adicionarItem(Item("Machado de Batalha", "arma", 1, 1, 3, 3));
        TelaCombate tc;
        tc.comecarCombate(personagem, orc);

        if (personagem->getEnergia() <= 0) {
            cout << "Tente novamente!" << endl;
        }
        else if (orc->getEnergia() <= 0) {
            personagem->setTesouro(personagem->getTesouro() + 5);
            cout << "+ 5 moedas de ouro" << endl;
            novaCena = 13;
        }
        else {
            novaCena = 13;
        }

        delete orc;
        return true;
    }
    else if (evento == "aprender_magia_cura") {
        if (dynamic_cast<Mago*>(personagem)) {
            personagem->adicionarMagia(Magia("Cura Menor", "cura", 3));
            cout << "Você aprendeu a magia 'Cura Menor'!" << endl;
        }
        else {
            cout << "Você não é um mago e não consegue entender os escritos arcanos do livro!" << endl;
        }
        novaCena = 15;
        return true;
    }
    else if (evento == "pegar_espada_negra") {
        if (dynamic_cast<Guerreiro*>(personagem)) {
            personagem->adicionarItem(Item("Espada Negra", "arma", 0, 1, 4, 3));
            cout << "Você encontrou a Espada Negra! Use o inventário durante uma batalha para equipá-la!" << endl;
        }
        else {
            cout << "Você não tem treinamento com espadas e decide deixá-la para trás." << endl;
        }
        novaCena = 17;
        return true;
    }
    else if (evento == "combate_chefe") {
        Monstro* necromante = new Monstro("Necromante Maldred", 1, 8, 20, 8, 10);
        necromante->adicionarItem(Item("Cajado das Sombras", "arma", 1, 1, 5, 4));
        TelaCombate tc;
        tc.comecarCombate(personagem, necromante);

        if (personagem->getEnergia() <= 0) {
            cout << "Tente novamente!" << endl;
        }
        else if (necromante->getEnergia() <= 0) {
            personagem->setTesouro(personagem->getTesouro() + 10);
            cout << "+ 10 moedas de ouro" << endl;
            novaCena = 19;
        }
        else {
            novaCena = 19;
        }

        delete necromante;
        return true;
    }
    else if (evento == "ir_para_10") {
        novaCena = 10;
        return true;
    }
    else if (evento == "ir_para_18") {
        novaCena = 18;
        return true;
    }
    return false;
}

bool TelaJogo::salvarPersonagem(const string& caminhoArquivo, Personagem* personagem) {
    ofstream arquivo(caminhoArquivo);

    if (!arquivo.is_open()) {
        cout << "Erro ao abrir o arquivo para salvar!" << endl;
        return false;
    }

    arquivo << personagem->getNome() << endl;
    arquivo << personagem->getClasse() << endl;
    arquivo << personagem->getHabilidade() << endl;
    arquivo << personagem->getEnergia() << endl;
    arquivo << personagem->getSorte() << endl;
    arquivo << personagem->getProvisoes() << endl;
    arquivo << personagem->getTesouro() << endl;
    for (const Item& item : personagem->getInventario()) {
        arquivo << item.getNome() << "," << item.getTipo() << "," << item.getEquipado() << "," << item.getCombate() << ","
        << item.getFA() << "," << item.getDano() << endl;
     }

     if (dynamic_cast<Mago*>(personagem)) {
        for (const Magia& magia : personagem->getMagias()) {
            arquivo << magia.getNome() << "," << magia.getTipo() << "," << magia.getValor() << endl;
        }
     }

     arquivo << personagem->getLugarHistoria() << endl;

    arquivo.close();
    cout << "Personagem salvo com sucesso!\n";
    return true;
}

bool TelaJogo::carregarPersonagem(const string& caminhoArquivo) {
    ifstream arquivo(caminhoArquivo);
    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir arquivo de personagem: " << caminhoArquivo << endl;
        return false;
    }

    string nome, classe;
    int habilidade, energia, sorte, provisoes, tesouro;
    int lugarHistoria = 1;

    if (!getline(arquivo, nome) || !getline(arquivo, classe)) {
        cerr << "Erro ao ler nome ou classe do personagem" << endl;
        return false;
    }

    if (!(arquivo >> habilidade >> energia >> sorte >> provisoes >> tesouro)) {
        cerr << "Erro ao ler atributos do personagem" << endl;
        return false;
    }
    arquivo.ignore();

    personagem.reset();
    if (classe == "Guerreiro") {
        personagem = make_unique<Guerreiro>(nome);
    } else if (classe == "Mago") {
        personagem = make_unique<Mago>(nome);
    } else {
        cerr << "Classe de personagem desconhecida: " << classe << endl;
        return false;
    }

    personagem->setHabilidade(habilidade);
    personagem->setEnergia(energia);
    personagem->setSorte(sorte);
    personagem->setProvisoes(provisoes);
    personagem->setTesouro(tesouro);

    personagem->limparInventario();
    personagem->limparMagias();

    string linha;
    while (getline(arquivo, linha)) {
        if (linha.empty()) continue;

        if (linha.find(',') == string::npos) {
            try {
                lugarHistoria = stoi(linha);
                personagem->setLugarHistoria(lugarHistoria);
                break;
            } catch (...) {
                cerr << "Erro ao ler posição na história: " << linha << endl;
            }
            continue;
        }

        stringstream ss(linha);
        string token;
        vector<string> tokens;

        while (getline(ss, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() == 3 && dynamic_cast<Mago*>(personagem.get())) {
            try {
                int valorMagia = stoi(tokens[2]);
                personagem->adicionarMagia(Magia(tokens[0], tokens[1], valorMagia));
            } catch (...) {
                cerr << "Erro ao ler magia: " << linha << endl;
            }
        } else if (tokens.size() == 6) {
            try {
                int equipado = stoi(tokens[2]);
                int combate = stoi(tokens[3]);
                int fa = stoi(tokens[4]);
                int dano = stoi(tokens[5]);
                personagem->adicionarItem(Item(tokens[0], tokens[1], equipado, combate, fa, dano));
            } catch (...) {
                cerr << "Erro ao ler item: " << linha << endl;
            }
        }
    }

    arquivo.close();

    if (!carregarHistoria("historia.txt")) {
        cerr << "Falha ao carregar a história" << endl;
        return false;
    }

    if (lugarHistoria <= 0 || lugarHistoria > static_cast<int>(cenas.size())) {
        cerr << "Posição na história inválida: " << lugarHistoria << endl;
        return false;
    }

    cenaAtual = lugarHistoria;
    iniciarHistoria(personagem.get());

    return true;
}

Personagem* TelaJogo::getPersonagem() {
    return personagem.get();
}
