  #include <stdio.h>
  #include <stdlib.h>
  #define MAX_EQ 28
  #define SALIR 3
  typedef struct Equipos{
      char NombreEquipo[30];
      int Puntos;
      struct Equipos *next;
  }equipo_t; 

  equipo_t * LPFA=NULL;
  void menu(void);
  void imprimir_equipo(equipo_t);
  void pedir_datos(equipo_t* Equipos);
  void ver_lista(void);
  void cargar_equipo(void);
  void liberar_memoria(void);

  int main(){
      menu();
      liberar_memoria();
      return 0;
  }

  void imprimir_equipo(equipo_t Equipo){
      printf("Equipo: %s\n",Equipo.NombreEquipo);
      printf("Puntos: %d\n",Equipo.Puntos);
      printf("-------------------------------------------------------------\n");

  }
  void pedir_datos(equipo_t * Equipos){
      printf("ingrese el nombre del equipo correspondiente (sin espacios):\n");
      scanf("%s",Equipos->NombreEquipo);
      printf("ingrese los puntos del equipo:\n");
      scanf("%d",&(Equipos->Puntos));

  }

  void menu(void){
      int opcion;
      do{
          printf("1_Cargar un nuevo equipo\n");
          printf("2_Ver todos los equipos cargados\n");
          printf("3_Salir\n");
          scanf("%d",&opcion);
          if(opcion==1)cargar_equipo();
          if(opcion==2)ver_lista();
      }while(opcion!=SALIR);

  }

  void cargar_equipo(){
      equipo_t *equipo_aux;
      equipo_aux=malloc(sizeof(equipo_t));
      if(equipo_aux==NULL){
          printf("Out of memory\n");
      }else{
          pedir_datos(equipo_aux);
          equipo_aux->next=LPFA;
          LPFA=equipo_aux;
      }


  }

  void ver_lista(void){
      equipo_t *lista=LPFA;
      while(lista!=NULL){
          imprimir_equipo(*lista);
          lista=lista->next;
      }
  }
  void liberar_memoria(void){
      equipo_t *aux=NULL;
      while(LPFA!=NULL){
          aux=LPFA;
          LPFA=LPFA->next;
          free(aux);

      }

  }