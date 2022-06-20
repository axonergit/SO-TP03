// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com
#include "levels.h"


static int compareAnswer(char *ans, size_t ansLen, FILE *input, char *correctAns);
static void obfuscateAnswer();
static void checkQuine();
static void gdbme();
static void boxMuller(double m, double s);
static void challengeHeader();
static void challengeQuestion();


static int compareAnswer(char *ans, size_t ansLen, FILE *input, char *correctAns) {

    fscanf(input, "%s",ans);

    printf("--> %s y %s\n\n", ans, correctAns);
    return (strcmp(ans, correctAns) == 0);
}

static void challengeHeader() {

    printf("------------- DESAFIO -------------\n");
}

static void challengeQuestion() {

    printf("\n----- PREGUNTA PARA INVESTIGAR -----\n");
}


int level1(char *ans, size_t ansLen, FILE *input) {

    challengeHeader();

    printf("Bienvenidos al TP3 y felicitaciones, ya resolvieron el primer acertijo.\n"
    "En este TP deberán finalizar el juego que ya comenzaron resolviendo los desafíos de cada nivel.\n"
    "Además tendrán que investigar otras preguntas para responder durante la defensa.\n"
    "El desafío final consiste en crear un programa que se comporte igual que yo, es decir, "
    "que provea los mismos desafíos y que sea necesario hacer lo mismo para resolverlos. "
    "No basta con esperar la respuesta.\n"
    "Además, deberán implementar otro programa para comunicarse conmigo.\n"
    "Deberán estar atentos a los easter eggs.\n"
    "Para verificar que sus respuestas tienen el formato correcto respondan a este desafío con la palabra 'entendido\\n'\n"
    );

    challengeQuestion();

    printf("¿Cómo descubrieron el protocolo, la dirección y el puerto para conectarse?\n");
    
    return compareAnswer(ans, ansLen, input, "entendido");
}


 int level2(char *ans, size_t ansLen, FILE *input) {

    challengeHeader();

    printf("The Wire S1E5\n"
    "5295 888 6288\n");

    challengeQuestion();

    printf("¿Qué diferencias hay entre TCP y UDP y en qué casos conviene usar cada uno?\n");

    return compareAnswer(ans, ansLen, input, "itba");
}

 int level3(char *ans, size_t ansLen, FILE *input) {

    challengeHeader();

    printf("https://ibb.co/tc0Hb6w \n");

    challengeQuestion();

    printf("¿El puerto que usaron para conectarse al server es el mismo que usan para mandar las respuestas? ¿Por qué?\n");

    return compareAnswer(ans, ansLen, input, "M4GFKZ289aku");
}

 int level4(char *ans, size_t ansLen, FILE *input) {

    challengeHeader();

    printf("EBADF...\n");

    if (write(69, "La respuesta es fk3wfLCm3QvS", 28) == ERROR_CODE) {
        // Must not be modified
        perror("write");
    }

    challengeQuestion();

    printf("¿Qué útil abstracción es utilizada para comunicarse con sockets? "
    "¿se puede utilizar read(2) y write(2) para operar?\n");
    
    return compareAnswer(ans, ansLen, input, "fk3wfLCm3QvS");
}

 int level5(char *ans, size_t ansLen, FILE *input) {

    challengeHeader();

    printf("respuesta = strings:277\n");

    challengeQuestion();

    printf("¿Cómo garantiza TCP que los paquetes llegan en orden y no se pierden?\n");

    return compareAnswer(ans, ansLen, input, "too_easy");
}

 int level6(char *ans, size_t ansLen, FILE *input) {

    challengeHeader();

    printf(".data .bss .comment ? .shstrtab .symtab .strtab\n");

    challengeQuestion();

    printf("Un servidor suele crear un nuevo proceso o thread para atender las conexiones entrantes. ¿Qué conviene más?\n");

    return compareAnswer(ans, ansLen, input, ".RUN_ME");
}

 int level7(char *ans, size_t ansLen, FILE *input) {

    challengeHeader();

    printf("Filter error\n\n");

    obfuscateAnswer();

    challengeQuestion();
        
    printf("¿Cómo se puede implementar un servidor que atienda muchas conexiones sin usar procesos ni threads?\n");

    return compareAnswer(ans, ansLen, input, "K5n2UFfpFMUN");

}

 int level8(char *ans, size_t ansLen, FILE *input) {

    challengeHeader();

    printf("¿?\n\n"
    "\033[0;30;40m La respuesta es BUmyYq5XxXGt \033[0m\n\n");

    challengeQuestion();

    printf("¿Qué aplicaciones se pueden utilizar para ver el tráfico por la red?\n");
    
    return compareAnswer(ans, ansLen, input, "BUmyYq5XxXGt");
}

 int level9(char *ans, size_t ansLen, FILE *input) {

    challengeHeader();

    printf("Latexme\n\n"
    "Si \n"
    "\\mathrm{d}y = u^v{\\cdot}(v'{\\cdot}\\ln{(u)}+v{\\cdot}\frac{u'}{u})\n"
    "entonces\n"
    "y = ?\n\n");

    challengeQuestion();

    printf("sockets es un mecanismo de IPC. ¿Qué es más eficiente entre sockets y pipes?\n");

    return compareAnswer(ans, ansLen, input, "u^v");

}
int level10(char *ans, size_t ansLen, FILE *input) {

    challengeHeader();

    printf("quine\n\n");       

    checkQuine();

    challengeQuestion();

    printf("¿Cuáles son las características del protocolo SCTP?\n");
           
    return compareAnswer(ans, ansLen, input, "chin_chu_lan_cha");
}

int level11(char *ans, size_t ansLen, FILE *input) {

    challengeHeader();

    printf("b gdbme y encontrá el valor mágico\n\n"
    "ENTER para reintentar.\n");

    gdbme();

    challengeQuestion();

    printf("¿Qué es un RFC?\n");

    return compareAnswer(ans, ansLen, input, "gdb_rules");

}

 int level12(char *ans, size_t ansLen, FILE *input) {

    challengeHeader();

    printf("Me conoces\n\n");

    for (int i = 0; i < 100; i++) {
        boxMuller(0, 1);
    }

    challengeQuestion();

    printf("\n\n¿Fue divertido?");

    return compareAnswer(ans, ansLen, input, "normal");
}

static void obfuscateAnswer() {

    char * ans = "La respuesta es K5n2UFfpFMUN";
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

    double y1;
    static double y2;
    static int useLast = 0;

    if (useLast) /* use value from previous call */ {
        y1 = y2;
        useLast = 0;
    } else {
        double  x1, x2, w;
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