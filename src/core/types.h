#pragma once

#include <string>

// Core simplified type system used by semantics, interpreter, and codegen
// for the initial standalone language pass.
enum class SimpleType { Int, Float, Bool, Void, String, Unknown };

inline std::string toString(SimpleType t) {
    switch (t) {
        case SimpleType::Int: return "int";
        case SimpleType::Float: return "float";
        case SimpleType::Bool: return "boolean";
        case SimpleType::Void: return "void";
        case SimpleType::String: return "string";
        case SimpleType::Unknown: default: return "unknown";
    }
}

inline bool isNumeric(SimpleType t) { return t == SimpleType::Int || t == SimpleType::Float; }
inline bool isBoolean(SimpleType t) { return t == SimpleType::Bool; }
inline bool isVoid(SimpleType t) { return t == SimpleType::Void; }
inline bool isString(SimpleType t) { return t == SimpleType::String; }
