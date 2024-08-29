#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    WINDOW* win = initscr();       // Inicializa a tela
    keypad(win, true);            // Habilita captura de teclas especiais
    nodelay(win, true);           // Não bloqueia a leitura de entrada
    noecho();                     // Não mostra os caracteres digitados
    curs_set(0);                  // Oculta o cursor

    int posX = 10, posY = 5;
    int dirX = 1, dirY = 1;
    
    srand(time(NULL)); // Inicializa o gerador de números aleatórios

    int foodX = rand() % 20, foodY = rand() & 20;

    while (true) {
        int pressed = wgetch(win);  // Captura a tecla pressionada
        if (pressed == 'q') {
            break;                 // Sai do loop se 'q' for pressionado
        }

        // Atualiza a posição do ponto
        posX += dirX;
        posY += dirY;

        if(posX == foodX && posY == foodY) {
            foodX = rand() % 20;
            foodY = rand() & 20;

            mvaddstr(posY, posX, "*");
        }

        // Verifica se o ponto saiu dos limites da tela
        if (posX <= 0 || posX >= COLS - 1) {
            dirX *= -1;
        }
        if (posY <= 0 || posY >= LINES - 1) {
            dirY *= -1;
        }

        // Limpa a tela
        erase();
        mvaddstr(posY, posX, "*"); // Desenha o ponto
        mvaddstr(foodY, foodX, "*"); // Desenha a comida

        // Atualiza a tela
        refresh();
        usleep(100000); // Aguarda um pouco para criar o efeito de movimento
    }

    endwin(); // Finaliza o uso do ncurses
    return 0;
}
