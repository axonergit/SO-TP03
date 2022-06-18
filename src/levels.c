#include "levels.h"

#define CHOSEN_PID 0x12345678

static int compareAnswer(char *ans, size_t ansLen, FILE *input, char *correctAns);
static void obfuscateAnswer();
static void checkQuine();
static void gdbme();
static void boxMuller(double m, double s);

static int compareAnswer(char *ans, size_t ansLen, FILE *input, char *correctAns){
    if(getLine(&ans, &ansLen, input) == ERROR) {
        errorHandler("Getline failed");
    }

    return (strcmp(ans, correctAns) == 0);
}

 int level1(char *ans, size_t ansLen, FILE *input) {
    printf("Bienvenidos al TP3 y felicitaciones, ya resolvieron el primer acertijo.\n\n"
           "En este TP deberán finalizar el juego que ya comenzaron resolviendo los desafíos de cada nivel.\n"
           "Además tendrán que investigar otras preguntas para responder durante la defensa.\n"
           "El desafío final consiste en crear un programa que se comporte igual que yo, es decir, que provea los\n"
           "mismos desafíos y que sea necesario hacer lo mismo para resolverlos. No basta con esperar la respuesta.\n"
           "Además, deberán implementar otro programa para comunicarse conmigo.\n\n"
           "Deberán estar atentos a los easter eggs.\n\n"
           "Para verificar que sus respuestas tienen el formato correcto respondan a este desafío con la palabra 'entendido\\n'\n\n"
           "----- PREGUNTA PARA INVESTIGAR -----\n"
           "¿Cómo descubrieron el protocolo, la dirección y el puerto para conectarse?\n"
    );
    
    return compareAnswer(ans, ansLen, input, "entendido\n");
}


 int level2(char *ans, size_t ansLen, FILE *input){
    printf("------------- DESAFIO -------------\n"
            "The wire S1E5\n"
           "5295 888 6288\n\n"
           "----- PREGUNTA PARA INVESTIGAR -----\n"
           "¿Qué diferencias hay entre TCP y UDP y en qué casos conviene usar cada uno?\n");

    return compareAnswer(ans, ansLen, input, "itba\n");
}

 int level3(char *ans, size_t ansLen, FILE *input){
    printf("------------- DESAFIO -------------\n"
            "https://ibb.co/tc0Hb6w\n"
           "----- PREGUNTA PARA INVESTIGAR -----\n"
           "¿El puerto que usaron para conectarse al server es el mismo que usan para mandar las respuestas? ¿Por qué?\n");

    return compareAnswer(ans, ansLen, input, "M4GFKZ289aku\n");
}

 int level4(char *ans, size_t ansLen, FILE *input) {
    printf("------------- DESAFIO -------------\n"
            "EBADF...\n\n");

    if (write(69, "La respuesta es fk3wfLCm3QvS", 28) == ERROR) {
        perror("write"); //ESTE NO CAMBIA; SE QUEDA ASI
    }

    printf("\n"
           "----- PREGUNTA PARA INVESTIGAR -----\n"
           "¿Qué útil abstracción es utilizada para comunicarse con sockets? ¿se puede utilizar read(2) y write(2) para operar?");
    
    return compareAnswer(ans, ansLen, input, "fk3wfLCm3QvS\n");
}

 int level5(char *ans, size_t ansLen, FILE *input) {
    printf("------------- DESAFIO -------------\n"
            "respuesta = strings:277\n"
           "----- PREGUNTA PARA INVESTIGAR -----\n"
           "¿Cómo garantiza TCP que los paquetes llegan en orden y no se pierden?\n");

    return compareAnswer(ans, ansLen, input, "too_easy\n");
}

 int level6(char *ans, size_t ansLen, FILE *input){
     printf("------------- DESAFIO -------------\n"
            ".plt .plt.got .text ? .fini\n\n"
            "----- PREGUNTA PARA INVESTIGAR -----\n"
            "Un servidor suele crear un nuevo proceso o thread para atender las conexiones entrantes. ¿Qué conviene más?");

    return compareAnswer(ans, ansLen, input, ".RUN_ME\n");
}

 int level7(char *ans, size_t ansLen, FILE *input){
        printf("------------- DESAFIO -------------\n"
            "Filter error\n\n");

        obfuscateAnswer();
         
        printf("----- PREGUNTA PARA INVESTIGAR -----\n"
           "¿Cómo se puede implementar un servidor que atienda muchas conexiones sin usar procesos ni threads?\n");

    return compareAnswer(ans, ansLen, input, "K5n2UFfpFMUN\n");

}

 int level8(char *ans, size_t ansLen, FILE *input){
    printf("------------- DESAFIO -------------\n"
           "¿?\n\n"
           "\033[0;30;40m La respuesta es BUmyYq5XxXGt \033[0m\n"
           "----- PREGUNTA PARA INVESTIGAR -----\n"
           "¿Qué aplicaciones se pueden utilizar para ver el tráfico por la red?");
    
    return compareAnswer(ans, ansLen, input, "BUmyYq5XxXGt\n");
}

 int level9(char *ans, size_t ansLen, FILE *input){
    printf("------------- DESAFIO -------------\n"
            "Latexme\n\n"
            "Si\n"
            " \\mathrm{d}y = u^v{\\cdot}(v'{\\cdot}\\ln{(u)}+v{\\cdot}\frac{u'}{u})\n"
            "entonces\n"
            "y =\n\n"
           "----- PREGUNTA PARA INVESTIGAR -----\n"
           "sockets es un mecanismo de IPC. ¿Qué es más eficiente entre sockets y pipes?\n");

    return compareAnswer(ans, ansLen, input, "u^v\n");

}
int level10(char *ans, size_t ansLen, FILE *input){
    printf("quine\n\n"
           "----- PREGUNTA PARA INVESTIGAR -----\n"
           "¿Cuáles son las características del protocolo SCTP?");

    checkQuine();

    return compareAnswer(ans, ansLen, input, "chin_chu_lan_cha\n");
}

int level11(char *ans, size_t ansLen, FILE *input){
    printf("------------- DESAFIO -------------\n"
            "b gdbme y encontrá el valor mágico\n\n"
            "ENTER para reintentar.\n");

    gdbme();

    printf("----- PREGUNTA PARA INVESTIGAR -----\n"
           "¿Qué es un RFC?\n");

    return compareAnswer(ans, ansLen, input, "gdb_rules\n");

}

 int level12(char *ans, size_t ansLen, FILE *input){
    printf("------------- DESAFIO -------------\n"
           "Me conoces\n\n");

    for (int i = 0; i < 100; i++) {
        boxMuller(0, 1);
    }

    printf("\n\n¿Fue divertido?");

    return compareAnswer(ans, ansLen, input, "normal\n");
}

static void obfuscateAnswer() {
    char *ans = "La respuesta es K5n2UFfpFMUN";
    int ansLen = strlen(ans);

    for (int i = 0; i < ansLen; i++) {
        int limit = (rand() % 11);
        for (int j = 0; j < limit; j++) {
            char toPrint[2] = {0};
            toPrint[0] = (rand() % (126 - 32 + 1) + 32);
            write(STDERR, toPrint, 1);
        }

        write(STDOUT, ans + i, 1);
    }
}

static void checkQuine() {
    int sysResp = system("gcc quine.c -o quine");

    if (!sysResp) {
        printf("¡Genial!, ya lograron meter un programa en quine.c, veamos si hace lo que corresponde.\n");
        sysResp = system("./quine | diff - quine.c");

        if (!sysResp) {
            printf("La respuesta es chin_chu_lan_cha\n");
        } else {
            printf("diff encontró diferencias\n");
        }
    }

    if (sysResp) {
        printf("ENTER para reintentar\n\n");
    }
}

static void gdbme() {
    if (getpid() == CHOSEN_PID) {
        printf("La respuesta es gdb_rules\n\n");
    } else {
        printf("ENTER para reintentar\n\n");
    }
}

/*
    (c) Copyright 1994, Everett F. Carter Jr.
    Permission is granted by the author to use
    this software for any application provided this
	copyright notice is preserved.
    https://github.com/ingenthr/memcachetest/blob/master/boxmuller.c
 */
/* normal random variate generator */
/* mean m, standard deviation s */
static void boxMuller(double m, double s) {
    double x1, x2, w, y1;
    static double y2;
    static int useLast = 0;

    if (useLast) /* use value from previous call */
    {
        y1 = y2;
        useLast = 0;
    } else {
        do {
            x1 = 2.0 * drand48() - 1.0;
            x2 = 2.0 * drand48() - 1.0;
            w = x1 * x1 + x2 * x2;
        } while (w >= 1.0);

        w = sqrt((-2.0 * log(w)) / w);
        y1 = x1 * w;
        y2 = x2 * w;
        useLast = 1;
    }

    double result = (m + y1 * s);

    printf("%.6f ", result);
}