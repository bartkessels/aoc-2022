#include "results/day4/Logic.hpp"

using namespace AOC2022::results::day4;

bool Logic::rangesIncludedInEachOther(std::shared_ptr<Range> rangeA, std::shared_ptr<Range> rangeB)
{
    bool rangeAInRangeB = rangeB->start <= rangeA->start && rangeB->end >= rangeA->end;
    bool rangeBInRangeA = rangeA->start <= rangeB->start && rangeA->end >= rangeB->end;

    return rangeAInRangeB || rangeBInRangeA;
}

bool Logic::rangesThatOverlap(std::shared_ptr<Range> rangeA, std::shared_ptr<Range> rangeB)
{
    bool rangeAStartOverlaps = rangeA->start >= rangeB->start && rangeA->start <= rangeB->end;
    bool rangeAEndOverlaps = rangeA->end >= rangeB->start && rangeA->end <= rangeB->end;
    bool rangeBStartOverlaps = rangeB->start >= rangeA->start && rangeB->start <= rangeA->end;
    bool rangeBEndOverlaps = rangeB->end >= rangeA->start && rangeB->end <= rangeA->end;

    return rangeAStartOverlaps || rangeAEndOverlaps || rangeBStartOverlaps || rangeBEndOverlaps;
}