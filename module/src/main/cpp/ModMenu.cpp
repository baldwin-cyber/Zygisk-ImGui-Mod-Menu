#include <Headers/ModMenu.hpp>
#include <Headers/Drawing.hpp>
#include <Headers/Utility.hpp>
#include <Headers/Logger.hpp>
#include "imgui.h"
#include <string>

// Oyundaki kütüphane adı (Genelde libil2cpp.so olur)
#define TARGET_LIBRARY "libil2cpp.so"

void ModMenu::DrawMenu(int width, int height) {
    static char sifre[64] = "";
    static bool girisYapildi = false;

    if (!girisYapildi) {
        ImGui::Begin("AYTEAMHACK GUVENLIK");
        ImGui::Text("Sisteme giris icin sifre girin:");
        ImGui::InputText("##sifre", sifre, sizeof(sifre));

        if (ImGui::Button("Giris Yap")) {
            // Şifren: ayteam123
            if (strcmp(sifre, "AYTEAM-MOD-ADMİN-GİRİŞ") == 0) {
                girisYapildi = true;
            }
        }
        ImGui::End();
    } else {
        ImGui::Begin("AYTEAMHACK VIP MENU");
        ImGui::Text("Hosgeldin Patron! Sistem Aktif.");
        ImGui::Separator();
        
        // Buraya hile butonlarını ekleyebilirsin
        if (ImGui::Button("Sekmeme (No Recoil)")) {
            // Kodlar buraya gelecek
        }
        
        ImGui::End();
    }
}

void ModMenu::HackThread() {
    Drawing::InitMenu(DrawMenu);

    do {
        LOGI("Hedef kütüphane bekleniyor...");
        sleep(1);
    } while (!Utility::IsLibraryLoaded(TARGET_LIBRARY));
    
    LOGI("Kütüphane yüklendi, AYTEAMHACK hazır!");
}
