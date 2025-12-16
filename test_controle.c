#include "unity.h"
#include "controle.c" // Inclui o código da lógica (simulação)

void setUp(void) {
    // Roda antes de cada teste
}

void tearDown(void) {
    // Roda depois de cada teste
}

// 1. O Básico
void test_VelocidadeNormal_DeveManterValor(void) {
    TEST_ASSERT_EQUAL_INT(80, ProcessarVelocidade(80));
}

// 2. Asserção com MENSAGEM 
void test_VelocidadeAcimaDoLimite_DeveCortarPara120(void) {
    int input = 150; 
    int resultado = ProcessarVelocidade(input);

    // Se isso falhar, vai imprimir a mensagem explicando o risco
    TEST_ASSERT_EQUAL_INT_MESSAGE(120, resultado, 
        "FALHA GRAVE: O limitador de seguranca nao ativou!");
}

// 3. Ignorando um Teste 
void test_ModoSport_DevePermitirVelocidadeAlta(void) {
    // Imagine que a função 'AtivarModoSport' ainda não existe no 'controle.c'
    // Usamos o IGNORE para o compilador pular essa parte sem dar erro
    
    TEST_IGNORE_MESSAGE("Funcionalidade 'Modo Sport' em desenvolvimento pela Equipe B");
    
    // O código abaixo nem será executado:
    // AtivarModoSport(true);
    // TEST_ASSERT_EQUAL_INT(150, ProcessarVelocidade(150));
}

// 4. Teste de Faixa (Bônus automotivo)
void test_Sensor_DeveEstarNaFaixa(void) {
    TEST_ASSERT_INT_WITHIN(5, 120, ProcessarVelocidade(118));
}

// 5. Testando Arrays (Simulando um pacote de dados da rede CAN)
void test_PacoteDeDados_DeveEstarCorreto(void) {
    // Imagine que o painel espera receber estes 3 bytes: [Velocidade, RPM, Temperatura]
    int pacoteEsperado[] = {100, 3000, 90};
    
    // Função fictícia que retornaria os dados atuais
    int pacoteRecebido[] = {100, 3000, 90}; 
    
    // Verifica se os 3 números batem exatamente, na ordem certa
    // O último número (3) é o tamanho do array
    TEST_ASSERT_EQUAL_INT_ARRAY(pacoteEsperado, pacoteRecebido, 3);
}

// A Main
int main(void) {
    UNITY_BEGIN();
    
    RUN_TEST(test_VelocidadeNormal_DeveManterValor);
    RUN_TEST(test_VelocidadeAcimaDoLimite_DeveCortarPara120);
    RUN_TEST(test_ModoSport_DevePermitirVelocidadeAlta); // Este vai aparecer como IGNORED
    RUN_TEST(test_Sensor_DeveEstarNaFaixa);
    RUN_TEST(test_PacoteDeDados_DeveEstarCorreto);
    
    return UNITY_END();
}