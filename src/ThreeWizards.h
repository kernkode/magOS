#pragma once
#include "pch.h"

class ThreeWizards {
    public:
        static inline Wizard* root = nullptr;

    public:
        bool loadCsv(const std::string path);
        void showAllInfo(Wizard* mago);
        static Wizard* searchNode(Wizard* node, int id);
};