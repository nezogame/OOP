#pragma once
class BitwiseLogicalOperations
{
public:
    // Функція для виконання бітового AND над двома числами
    template <typename T>
    static T bitwise_AND(T a, T b) {
        return a & b;
    }

    // Функція для виконання бітового OR над двома числами
    template <typename T>
    static T bitwise_OR(T a, T b) {
        return a | b;
    }

    // Функція для виконання бітового XOR над двома числами
    template <typename T>
    static T bitwise_XOR(T a, T b) {
        return a ^ b;
    }
};



