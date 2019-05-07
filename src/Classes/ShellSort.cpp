#include "../Headers/ShellSort.h";

/**
 * Utiliza o algortimo de shellSort para ordenar um dado array de registros
 *
 * @param Registro arr[]
 * @param  int tam
 * @return nada
*/
void ShellSort::shellSort(Registro arr[], int tam)
{
    int i,j;
    // Comeca o algoritmo com uma lacuna grande entre as chaves e vai sempre
    // dividindo por 2 o tamanho em cada interação
    for (int lacuna = tam/2; lacuna > 0; lacuna /= 2)
    {
        // percorre a lacuna que acabou de ser dividida
        for (i = lacuna; i < tam; i += 1)
        {
            // pega o pivo para essa lacuna
            int pivo = arr[i].getUserId();

            // compara o elementos da lacuna e faz a troca dos elementos quando necessaria
            for (j = i; j >= lacuna && arr[j - lacuna].getUserId() > pivo; j -= lacuna)
                arr[j].setUserId(arr[j - lacuna].getUserId());

            // volta o pivo para sua posicao inicial
            arr[j].setUserId(pivo);
        }
    }

}
