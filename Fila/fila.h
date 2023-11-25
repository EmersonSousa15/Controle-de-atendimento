// Definição de uma estrutura representando uma fila (Fila).
typedef struct fila Fila;

// Função para criar e inicializar uma nova fila.
Fila* criarFila();

// Função para enfileirar (inserir) um novo elemento (senha) na fila.
void enfileirar(Fila *f, int senha);

// Função para desenfileirar (remover e retornar) a senha da frente da fila.
int desenfileirar(Fila *f);

// Função para visualizar (imprimir) o conteúdo da fila.
void visualizarFila(Fila *f);

// Função para verificar se a fila está vazia.
// Retorna 1 se a fila estiver vazia, 0 caso contrário.
int filaVazia(Fila *f);

// Função para verificar se a fila está cheia.
// Retorna 1 se a fila estiver cheia, 0 caso contrário.
int filaCheia(Fila* f);

// Função que libera o espaço alocado da fila. 
void liberaFila(Fila *p);
