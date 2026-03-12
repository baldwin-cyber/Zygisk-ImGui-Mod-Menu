//
// Created by BALDWİN on 1/6/2025.
//
#include <Headers/ModMenu.hpp>
#include <string>
#include <iostream>
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
        ImGui::InputText("##sifre", sifre, sizeof(sifre), ImGuiInputTextFlags_Password);
        
        if (ImGui::Button("Giris Yap")) {
            // "ayteam123" yazan yere kendi gizli şifreni yaz!
            if (strcmp(sifre, "ayteam123") == 0) { 
                girisYapildi = true;
            }
        }
        ImGui::End();
    } else {
        // --- ASIL VIP MENÜ ---
        ImGui::Begin("AYTEAMHACK VIP MENU");
        
        ImGui::Text("Sisteme Hosgeldin Patron!");
        ImGui::Separator();
        
        // Hile butonlarını ve özelliklerini daha sonra buraya ekleyeceğiz
        ImGui::Text("Ozellikler yakinda eklenecek...");
        
        ImGui::End();
    }

void ModMenu::HackThread() {
    Drawing::InitMenu(DrawMenu);

    do {
        LOGI("Waiting for target library to load to load");
        sleep(1);
    } while (Utility::IsLibraryLoaded(TARGET_LIBRARY));
    LOGI("Target library loaded at 0x%lu", Utility::GetBaseAddress(TARGET_LIBRARY));

    //Hooks and Patches here

    LOGI("ModMenu initialized");
}
