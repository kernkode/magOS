#pragma once
#include "pch.h"

class ThreeWizards {
    public:
        enum e_info_flags{
            SHOW_ALIVE = 1 << 0, //00000001
            SHOW_DEAD = 1 << 1, //00000010
            SHOW_OWNER = 1 << 2 //00000100
        };
        static inline Wizard* root = nullptr;

    public:
        bool loadCsv(const std::string path);
        void showAllInfo(Wizard* mago, uint16_t flags);
        static Wizard* searchNode(Wizard* node, int id);
        void addNode(Wizard* wizard, Wizard* child);
};