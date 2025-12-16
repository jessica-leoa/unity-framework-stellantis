#include <stdbool.h>

// Função que limita a velocidade a 120
int ProcessarVelocidade(int velocidadeEntrada) {
    if (velocidadeEntrada > 120) {
        return 120;
    }
    return velocidadeEntrada;
}

// Verifica se o sistema de freio está ativo (Simulação)
bool SistemaFreioAtivo(void) {
    return true; // Vamos simular que está sempre ativo por segurança
}