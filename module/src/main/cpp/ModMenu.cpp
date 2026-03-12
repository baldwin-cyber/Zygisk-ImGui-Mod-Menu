//
// Created by AYTEAMHACK
//

#include <Headers/ModMenu.hpp>
#include <Headers/Drawing.hpp>
#include <Headers/Utility.hpp>

#include "imgui.h"

#define TARGET_LIBRARY "libil2cpp.so"

void ModMenu::DrawMenu(int width, int height) {
    static char sifre[64] = "";
    static bool girisYapildi = false;

    if (!girisYapildi) {
        // --- ŞİFRE EKRANI ---
        ImGui::Begin("AYTEAMHACK GUVENLIK");
        ImGui::Text("Sisteme giris icin sifre girin:");
        ImGui::InputText("##sifre", sifre, sizeof(sifre));

        if (ImGui::Button("Giris Yap")) {
            // Şifre: ayteam123
            if (strcmp(sifre, "AYTEAM-MOD-ADMİN-GİRİŞ") == 0) {
                girisYapildi = true;
            }
        }
        ImGui::End();
    } else {
        // --- ASIL VIP MENÜ ---
        ImGui::Begin("AYTEAMHACK VIP MENU");
        
        ImGui::Text("Sisteme Hosgeldin Patron!");
        ImGui::Separator();
        
        // Hile butonlarını ve özellikleri buraya ekleyeceğiz
        ImGui::Text("Ozellikler yakinda eklenecek...");
        
        ImGui::End();
    }
}

void ModMenu::HackThread() {
    Drawing::InitMenu(DrawMenu);

    do {
        LOGI("Waiting for target library to load");
        sleep(1);
    } while (!Utility::IsLibraryLoaded(TARGET_LIBRARY));
    
    LOGI("Target library loaded");

    //Hooks and Patches here

    LOGI("ModMenu initialized");
}
