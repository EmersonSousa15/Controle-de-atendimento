// Definição de uma estrutura representando uma pilha (Pilha).
typedef struct pilha Pilha;

// Função para criar e inicializar uma nova pilha.
Pilha* criarPilha();

// Função para empilhar (inserir) um novo elemento (senha) na pilha e um tipo.
void empilhar(Pilha *p, int senha, char tipo);

// Função para desempilhar (remover e retornar) o elemento do topo da pilha.
int desempilhar(Pilha *p);

// Função para verificar se a pilha está vazia.
// Retorna 1 se a pilha estiver vazia, 0 caso contrário.
int pilhaVazia(Pilha *p);

// Função para visualizar (imprimir) o conteúdo da pilha.
void visualizarPilha(Pilha *p);

// Função que libera o espaço alocado da pilha. 
void liberaPilha(Pilha *p);
