#include "common/pfr_extension.hpp"

struct Point
{
    int x;
};

void foo()
{
    common::visit_object(Point {}, []<typename Info>(auto&& field) {

    });
}