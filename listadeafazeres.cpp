#include <iostream>
#include <vector>
#include <locale>

using namespace std;

void exibirLista(const vector<string>& lista) {
    cout << endl;

    if (lista.empty()) {
        cout << "N�o h� tarefas no momento." << endl;
    } else {
        cout << "Lista de Tarefas:" << endl;
        for (size_t i = 0; i < lista.size(); ++i) {
            cout << i + 1 << ". " << lista[i] << endl;
        }
        cout << endl;
    }

    cout << "\nClique Enter para continuar." << endl;
    cin.ignore();
}

void exibirMenu() {
    cout << "========= Menu Principal =========" << endl;
    cout << "- Visualizar Lista de Tarefas " << endl;
    cout << "- Adicionar Tarefa " << endl;
    cout << "- Remover Tarefa " << endl;
    cout << "- Sair do Programa " << endl;
    cout << "===================================" << endl;
    cout << "Escreva com base na a��o desejada: lista, adicionar, remover ou sair:" << endl;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    vector<string> listaDeTarefas;

    while (true) {
        exibirMenu();
        string acao;
        getline(cin, acao);

        if (acao == "lista") {
            exibirLista(listaDeTarefas);
        } else if (acao == "adicionar") {
            cout << "\nDigite uma nova tarefa: ";
            string novaTarefa;
            getline(cin, novaTarefa);
            listaDeTarefas.push_back(novaTarefa);
            cout << "\nTarefa adicionada com sucesso! Clique Enter para continuar." << endl;
            cin.ignore();
        } else if (acao == "remover") {
            exibirLista(listaDeTarefas);

            if (listaDeTarefas.empty()) {
                cout << "\nN�o h� nada para ser removido, a lista de tarefas est� vazia." << endl;
            } else {
                cout << "\nDigite o n�mero da tarefa a ser removida (1-" << listaDeTarefas.size() << "): ";
                int numeroTarefa;
                cin >> numeroTarefa;

                if (numeroTarefa >= 1 && numeroTarefa <= static_cast<int>(listaDeTarefas.size())) {
                    listaDeTarefas.erase(listaDeTarefas.begin() + numeroTarefa - 1);
                    cout << "\nTarefa removida com sucesso!\n" << endl;
                } else {
                    cout << "\nN�mero de tarefa inv�lida.\n" << endl;
                }

                cin.ignore();
            }
        } else if (acao == "sair") {
            cout << "\nPrograma encerrado. Obrigado!\n" << endl;
            break;
        } else {
            cout << "\nA��o inv�lida, tente novamente. Clique Enter para continuar.\n" << endl;
            cin.ignore();
        }
    }

    return 0;
}
