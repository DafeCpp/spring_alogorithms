#ifndef CONSTS
#define CONSTS
#include <limits>
// SAH
constexpr double Ct{1};  // стоимость прослеживания луча внутри узла
constexpr double Ci{1};  // стоимость пересечения (плоскостью) лучом
constexpr double PARITION{33};  // разбиение по оси

constexpr double NONE{std::numeric_limits<double>::max()};
constexpr int max_parallel_depth{4};
#endif