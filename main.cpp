#include <cstdlib>
#include <iostream>

using namespace std;

char* mensagem;
int chave;
int cripto = -1;

void configuracaoErrada() {
    cout << "Configuração mal realizada. Por favor, utilize a opção -h.";
}

void mostrarAjuda() {
    cout << "---- Instituto Federal de Rondônia - Campus Ariquemes ----" << endl;
    cout << "Criptografa e descriptografa mensagens usando Cifra de César" << endl;
    cout << "N. A. V. Simões <natanael.simoes@ifro.edu.br>" << endl;
    cout << "http://github.com/ifroariquemes/CifraCesar" << endl << endl;
    cout << "Uso:" << endl << endl;
    cout << "      cesar -c|-d mensagem -k chave" << endl << endl;
    cout << " -c mensagem      Criptografa uma mensagem" << endl;
    cout << " -d mensagem      Decriptografa uma mensagem" << endl;
    cout << " -k chave         Aplica uma chave na de/criptografia" << endl;
    cout << " -h               Mostra essa mensagem" << endl;
    cout << " Criptografar: cesar -c mensagem -k 3" << endl;
    cout << " Decriptografar: cesar -d phqvdjhp -k 3" << endl;
}

void criptografar() {
    int diferenca;
    char novaLetra;
    for (int i = 0; mensagem[i] != '\0'; i++) {
        novaLetra = mensagem[i] + chave;
        if (mensagem[i] <= 'z' && novaLetra > 'z') {
            diferenca = chave - ('z' - mensagem[i]) - 1;
            novaLetra = 'a' + diferenca;
        } else if (mensagem[i] <= 'Z' && novaLetra > 'Z') {
            diferenca = chave - ('Z' - mensagem[i]) - 1;
            novaLetra = 'A' + diferenca;
        }
        cout << novaLetra;
    }
}

void descriptografar() {
    int diferenca;
    char novaLetra;
    for (int i = 0; mensagem[i] != '\0'; i++) {
        novaLetra = mensagem[i] - chave;
        if (mensagem[i] >= 'a' && novaLetra < 'a') {
            diferenca = chave - (mensagem[i] - 'a') - 1;
            novaLetra = 'z' - diferenca;
        } else if (mensagem[i] >= 'A' && novaLetra < 'A') {
            diferenca = chave - (mensagem[i] - 'A') - 1;
            novaLetra = 'Z' - diferenca;
        }
        cout << novaLetra;
    }
}

int main(int argc, char** argv) {
    for (int i = 0; i < argc; i++) {
        if (argv[i][0] == '-' && argv[i][2] == '\0') { // Parametro chegando
            switch (argv[i][1]) {
                case 'd':
                    mensagem = argv[++i];
                    cripto = 0;
                    break;
                case 'c':
                    mensagem = argv[++i];
                    cripto = 1;
                    break;
                case 'k':
                    if (i + 1 < argc)
                        chave = atoi(argv[++i]);
                    break;
                case 'h':
                    if (argc > 2) {
                        configuracaoErrada();
                        return 1;
                    }
                    mostrarAjuda();
                    return 0;
                default:
                    configuracaoErrada();
                    return 1;
            }
        }
    }
    switch (cripto) {
        case -1:
            configuracaoErrada();
            return 1;
            break;
        case 1:
            criptografar();
            break;
        case 0:
            descriptografar();
            break;
    }
    return 0;
}

