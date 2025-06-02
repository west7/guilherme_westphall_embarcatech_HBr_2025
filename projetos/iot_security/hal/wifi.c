#include "inc/wifi.h"


/**
 * Função para conectar ao Wi-Fi.
 * 
 * @param ssid O SSID da rede Wi-Fi.
 * @param password A senha da rede Wi-Fi.
 */
int connect_wifi(const char *ssid, const char *password) 
{
    if (cyw43_arch_init()) {
        printf("Erro ao inicializar Wi-Fi.\n");
        return -1;
    }

    cyw43_arch_enable_sta_mode();

    if (cyw43_arch_wifi_connect_timeout_ms(ssid, password, CYW43_AUTH_WPA2_AES_PSK, 30000)) {
        printf("Erro ao conectar.\n");
        return -1;
    }
    
    printf("Conectado à: %s.\n", ssid);
    return 1;
}