#include <Headers/ModMenu.hpp>
#include <jni.h>
#include <string>
#include <unistd.h>
#include "Headers/ModMenu.hpp"
#include "Headers/Drawing.hpp"
#include "Headers/Utility.hpp"
#include "Headers/Logger.hpp"
#include "imgui.h"

#define TARGET_LIBRARY "libil2cpp.so"

void ModMenu::DrawMenu(int width, int height) {
    static char sifre[64] = "";
    static bool girisYapildi = false;

    if (!girisYapildi) {
        ImGui::Begin("AYTEAMHACK GUVENLIK");
        ImGui::Text("Sifre Giriniz:");
        ImGui::InputText("##key", sifre, 64);
        if (ImGui::Button("Giris Yap")) {
            if (strcmp(sifre, "ayteam123") == 0) {
                girisYapildi = true;
            }
        }
        ImGui::End();
    } else {
        ImGui::Begin("AYTEAMHACK VIP");
        ImGui::Text("Sisteme Hosgeldin Patron!");
        ImGui::End();
    }
}

void ModMenu::HackThread() {
    Drawing::InitMenu(DrawMenu);
    do {
        sleep(1);
    } while (!Utility::IsLibraryLoaded(TARGET_LIBRARY));
}
