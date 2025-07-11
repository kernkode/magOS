#pragma once
#include "pch.h"

class ThreeWizards {
    public:
        Wizard* root;

    public:
        ThreeWizards();
        ~ThreeWizards();

    public:
        bool loadCsv(const std::string path);
        void showInfo(Wizard* mago);
};