* Francisco Colín Ulises 
Proyecto final, Exámen No. 2*/

#include <stdio.h>

// Prototipo de la funcion (una por cada inciso)
void In1CapturadeVotos ();          					            // Inciso 1: Lectura y almacenamiento
void In2CalculodeVotos ();          					            // Inciso 2: Cálculo de votos y lugares de la canción
void In3ObtdeOyenGanyMostrarResultados ();                          // Inciso 3: Obtención del oyente ganador y resultados

// Variables globales
int CancionNo1 = 0;          			    // Canción más votada       
int CancionNo2 = 0;          			    // Segunda canción más votada    
int OyenGanador = 0;         			    // Oyente ganador
int OyenCapturados = 0;      			    // Número total de oyentes registrados

// Constantes globales
int LimiteOyentes   = 100;  			    // Número máximo de oyentes
int TotalCanciones  = 10;   			    // Número de canciones disponibles
int VotosPorOyente  = 3;    			    // Cada oyente da 3 votos

// Matriz y arreglos
int VotosOyentes [100][3];    			  	// Matriz [Oyente][Voto]
int PuntosPorCancion [10];   			    // Arreglo con puntos de cada canción
int PuntosPorOyente [100];    			  	// Arreglo de puntos por cada oyente

// Función principal: Se llaman las 3 funciones correspondientes (cada función ya realiza lo necesario según su inciso)

void main ()
{
    // Función 1 (lectura y almacenamiento)
    	  // Aquí se llena la matriz VotosOyentes, con los votos registrados
    	  // Se guardan cuántos oyentes participaron
    In1CapturadeVotos ();

    // Funcíon 2 (cálculo de votos y lugar de la canción)
    	  // Se suman los puntos por canción
    	  // Además se determinala canción ganadora y la segunda más votada
    In2CalculodeVotos ();

    // Función 3 (obtención del oyente ganador y resultados)
    	  // Aquí se muestra el ganador del concurso
    In3ObtdeOyenGanyMostrarResultados ();
}

// Función del inciso 1 (lectura y almacenamiento)
   
void In1CapturadeVotos ()
{
    int i = 0;						                      // Contador del número de oyentes
    int v1 = 0, v2 = 0, v3 = 0;		              		  // Variables para almacenar los votos del oyente

    printf("Concurso para determinar: LA MEJOR CANCION DEL MES\n\n");
    printf("Cada oyente votara 3 canciones, estan enlistadas del (0 al 9).\n");
    printf("Para separar un voto del otro, basta con dar un espacio entre estos.\n");
    printf("Si desea terminar, escriba (-1) en la primera cancion a votar.\n\n");

	printf("Votos asignados por:  \n");
    printf("  Oyente No. %d:  ", i);									       // Muestra el número del primer oyente  					
	scanf("%d %d %d", &v1, &v2, &v3);									       // Se pide los votos del primer oyente, para que el While comience correctamente


    while (v1 != -1 && i < LimiteOyentes)								       // Ciclo para capturar votos mientras no se ingrese -1 y no se exceda el límite
    {
        VotosOyentes[i][0] = v1;										       // Guardan los 3 votos del oyente actual 
        VotosOyentes[i][1] = v2;
        VotosOyentes[i][2] = v3;

        i++; 														           // Se incrementa el contador de oyentes

        printf("  Oyente No. %d:  ", i);								       // Asigna el numero o lugar del siguiente oyente 					
		scanf("%d %d %d", &v1, &v2, &v3);							           // Solicita votos del siguiente oyente 	
    }

    OyenCapturados = i;													       // Se guarda cuántos oyentes participaron realmente
}									

// Función del inciso 2 (cálculo de votos y lugares de la canción)

void In2CalculodeVotos ()
{
    int i = 0;				                  // Contador para recorrer oyentes
	int c = 0;				                  // Contador para recorrer canciones

	// Inicialización del arreglo de puntos: todas las canciones empiezan con 0
    for (c = 0; c < TotalCanciones; c++)								
    {
        PuntosPorCancion[c] = 0;
    }

    for (i = 0; i < OyenCapturados; i++)							     // Suma de votos según la posición del voto de cada oyente
    {
    	PuntosPorCancion[VotosOyentes[i][0]] = PuntosPorCancion[VotosOyentes[i][0]] + 3;				        // Primer lugar, más 3 votos

        PuntosPorCancion[VotosOyentes[i][1]] = PuntosPorCancion[VotosOyentes[i][1]] + 2;				        // Segundo lugar, más 2 votos

        PuntosPorCancion[VotosOyentes[i][2]] = PuntosPorCancion[VotosOyentes[i][2]] + 1;				        // Tercer lugar, más 1 voto
    }

	// Busqueda de la canción más votada	
    int max1 = -1;									
    CancionNo1 = -1;		                                  			  // Primer lugar, se inicializan en -1 porque todas las canciones tienen 0 o más puntos y puede a haber un error si es en 0				
	  
    for (c = 0; c < TotalCanciones; c++)								
    {
        if (PuntosPorCancion[c] > max1)									  // Se excluye la canción ganadora y se busca la mejor entre las restantes
        {
            max1 = PuntosPorCancion[c];									
            CancionNo1 = c;
        }
    }
	
	// Busqueda de la segunda cancián más votada						
    int max2 = -1;														
    CancionNo2 = -1;		// Segundo lugar													

    for (c = 0; c < TotalCanciones; c++)
    {
        if (c != CancionNo1 && PuntosPorCancion[c] > max2)
        {
            max2 = PuntosPorCancion[c];
            CancionNo2 = c;
        }
    }
}

// Función del inciso 3 (obtención del oyente ganador y resultados)

void In3ObtdeOyenGanyMostrarResultados ()
{
    int i = 0, numvoto = 0, votostot = 0;                   // Contador y acumuladores
    int maxPuntos = -1;                                     // Máximo puntaje encontrado

    // Inicializa puntos de los oyentes
    for (i = 0; i < OyenCapturados; i++)
    {
        PuntosPorOyente[i] = 0;
    }

    // Calcular puntos obtenidos por cada oyente
    for (i = 0; i < OyenCapturados; i++) 
    {
        votostot = 0;                                                     // Cada oyente empieza en 0 puntos

        for (numvoto = 0; numvoto < VotosPorOyente; numvoto++)                      
        {
            if (VotosOyentes[i][numvoto] == CancionNo1)
            {
                votostot = 30 + votostot;                                 // Puntos por cancion del primer lugar, más 30 puntos
            }
            else
            {
                if (VotosOyentes[i][numvoto] == CancionNo2)
                {
                    votostot = 20 + votostot;                             // Puntos por cancion del segundo lugar, más 20 puntos
                }
                else
                {
                    if (votostot == 50)
                    {
                        votostot = 60;                                    // Puntos por cancion del primero y segundo lugar, más 60 puntos
                    } 
                }
            }
        }

        PuntosPorOyente[i] = votostot;                                    // Se guardan los puntos obtenidos 

        // Verifica cual es el de mayor puntaje
        if (PuntosPorOyente[i] > maxPuntos)         
        {
            maxPuntos = PuntosPorOyente[i];
            OyenGanador = i;                                              // Se actualiza el oyente ganador 
        }
    }

    // Mostrar resultados finales
    printf("\n\nResultados obtenidos: \n");

    printf("\nVotos recibidos por cancion: \n");                          // Muestra votos acumulados por canción
    for (i = 0; i < TotalCanciones; i++)
    {
        printf("  Cancion %d: %d votos\n", i, PuntosPorCancion[i]);
    }

    printf("\nLugar obtenido por las canciones mas votadas: \n");         // Muestra Cancion mas votada
    printf("  Primer lugar para la cancion:  %d\n", CancionNo1);
    printf("  Segundo lugar para la cancion: %d\n", CancionNo2);

    printf("\nPuntos asignados para cada oyente:\n");                     // Muestra puntos por oyente
    for (i = 0; i < OyenCapturados; i++)
    {
        printf("  Oyente %d: %d puntos\n", i, PuntosPorOyente[i]);
    }
    
    printf("\nOyente ganador: \n");                                       // Muestra ganador final
    printf("  Fue el No. %d  con  %d  puntos\n", OyenGanador, PuntosPorOyente[OyenGanador]);
}
