#pragma once

template <typename T>
class ComparateurQuantite
{
public:
    bool operator()(const T &a, const T &b) const
    {
        // I am dumb
        return (a.getQuantite() < b.getQuantite()) ? false : ((a.getQuantite() == b.getQuantite()) ?  (a < b) : true);
    }
};