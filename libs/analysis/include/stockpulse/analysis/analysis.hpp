#pragma once

#include <string_view>

// Wskazniki i wykrywanie anomalii (rolling mean/std, z-score). Czysta matematyka, bez I/O.
namespace stockpulse::analysis
{
    // Zaslepka: potwierdza, ze modul sie buduje i linkuje. Do zastapienia prawdziwym API.
    std::string_view module_name();
}
