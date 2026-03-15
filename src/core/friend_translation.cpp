#include "friend_translation.h"

#include <array>

namespace FriendTranslation {

namespace {

using DoubleInvoker = double (*)(void *, const std::vector<double> &);
using IntInvoker = int (*)(void *, const std::vector<int> &);

#define EZ_MAKE_DOUBLE_INVOKER(sig, call)                                                           \
    [](void *sym, const std::vector<double> &args) -> double {                                      \
        using Fn = double (*) sig;                                                                   \
        return reinterpret_cast<Fn>(sym) call;                                                       \
    }

#define EZ_MAKE_INT_INVOKER(sig, call)                                                               \
    [](void *sym, const std::vector<int> &args) -> int {                                             \
        using Fn = int (*) sig;                                                                      \
        return reinterpret_cast<Fn>(sym) call;                                                       \
    }

const std::array<DoubleInvoker, kMaxFriendCallArgs + 1> kDoubleInvokers = {{
    EZ_MAKE_DOUBLE_INVOKER((), ()),
    EZ_MAKE_DOUBLE_INVOKER((double), (args[0])),
    EZ_MAKE_DOUBLE_INVOKER((double, double), (args[0], args[1])),
    EZ_MAKE_DOUBLE_INVOKER((double, double, double), (args[0], args[1], args[2])),
    EZ_MAKE_DOUBLE_INVOKER((double, double, double, double), (args[0], args[1], args[2], args[3])),
    EZ_MAKE_DOUBLE_INVOKER((double, double, double, double, double), (args[0], args[1], args[2], args[3], args[4])),
    EZ_MAKE_DOUBLE_INVOKER((double, double, double, double, double, double), (args[0], args[1], args[2], args[3], args[4], args[5])),
    EZ_MAKE_DOUBLE_INVOKER((double, double, double, double, double, double, double), (args[0], args[1], args[2], args[3], args[4], args[5], args[6])),
    EZ_MAKE_DOUBLE_INVOKER((double, double, double, double, double, double, double, double), (args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7])),
    EZ_MAKE_DOUBLE_INVOKER((double, double, double, double, double, double, double, double, double), (args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8])),
    EZ_MAKE_DOUBLE_INVOKER((double, double, double, double, double, double, double, double, double, double), (args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9])),
    EZ_MAKE_DOUBLE_INVOKER((double, double, double, double, double, double, double, double, double, double, double), (args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10])),
    EZ_MAKE_DOUBLE_INVOKER((double, double, double, double, double, double, double, double, double, double, double, double), (args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11])),
    EZ_MAKE_DOUBLE_INVOKER((double, double, double, double, double, double, double, double, double, double, double, double, double), (args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12])),
    EZ_MAKE_DOUBLE_INVOKER((double, double, double, double, double, double, double, double, double, double, double, double, double, double), (args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12], args[13])),
    EZ_MAKE_DOUBLE_INVOKER((double, double, double, double, double, double, double, double, double, double, double, double, double, double, double), (args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12], args[13], args[14])),
    EZ_MAKE_DOUBLE_INVOKER((double, double, double, double, double, double, double, double, double, double, double, double, double, double, double, double), (args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12], args[13], args[14], args[15])),
}};

const std::array<IntInvoker, kMaxFriendCallArgs + 1> kIntInvokers = {{
    EZ_MAKE_INT_INVOKER((), ()),
    EZ_MAKE_INT_INVOKER((int), (args[0])),
    EZ_MAKE_INT_INVOKER((int, int), (args[0], args[1])),
    EZ_MAKE_INT_INVOKER((int, int, int), (args[0], args[1], args[2])),
    EZ_MAKE_INT_INVOKER((int, int, int, int), (args[0], args[1], args[2], args[3])),
    EZ_MAKE_INT_INVOKER((int, int, int, int, int), (args[0], args[1], args[2], args[3], args[4])),
    EZ_MAKE_INT_INVOKER((int, int, int, int, int, int), (args[0], args[1], args[2], args[3], args[4], args[5])),
    EZ_MAKE_INT_INVOKER((int, int, int, int, int, int, int), (args[0], args[1], args[2], args[3], args[4], args[5], args[6])),
    EZ_MAKE_INT_INVOKER((int, int, int, int, int, int, int, int), (args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7])),
    EZ_MAKE_INT_INVOKER((int, int, int, int, int, int, int, int, int), (args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8])),
    EZ_MAKE_INT_INVOKER((int, int, int, int, int, int, int, int, int, int), (args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9])),
    EZ_MAKE_INT_INVOKER((int, int, int, int, int, int, int, int, int, int, int), (args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10])),
    EZ_MAKE_INT_INVOKER((int, int, int, int, int, int, int, int, int, int, int, int), (args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11])),
    EZ_MAKE_INT_INVOKER((int, int, int, int, int, int, int, int, int, int, int, int, int), (args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12])),
    EZ_MAKE_INT_INVOKER((int, int, int, int, int, int, int, int, int, int, int, int, int, int), (args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12], args[13])),
    EZ_MAKE_INT_INVOKER((int, int, int, int, int, int, int, int, int, int, int, int, int, int, int), (args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12], args[13], args[14])),
    EZ_MAKE_INT_INVOKER((int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int), (args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12], args[13], args[14], args[15])),
}};

#undef EZ_MAKE_DOUBLE_INVOKER
#undef EZ_MAKE_INT_INVOKER

} // namespace

bool isSupportedArgumentType(SimpleType type)
{
    return type == SimpleType::Int || type == SimpleType::Float || type == SimpleType::Bool;
}

std::string supportedArgumentTypeMessage()
{
    return "friend calls support only int, float, and boolean arguments";
}

std::string tooManyArgumentsMessage(std::size_t maxArgs)
{
    return "friend calls support up to " + std::to_string(maxArgs) + " arguments";
}

bool prepareArguments(const std::vector<FriendScalar> &args,
                      PreparedFriendArgs &prepared,
                      std::string &errorMessage)
{
    prepared = PreparedFriendArgs{};

    if (args.size() > kMaxFriendCallArgs) {
        errorMessage = tooManyArgumentsMessage();
        return false;
    }

    prepared.useFloatCall = shouldUseFloatCall(args);

    if (prepared.useFloatCall) {
        prepared.doubleArgs.reserve(args.size());
    } else {
        prepared.intArgs.reserve(args.size());
    }

    for (const auto &arg : args) {
        if (!isSupportedArgumentType(arg.type)) {
            errorMessage = supportedArgumentTypeMessage();
            return false;
        }
        if (prepared.useFloatCall) {
            prepared.doubleArgs.push_back(toDoubleArg(arg));
        } else {
            prepared.intArgs.push_back(toIntArg(arg));
        }
    }

    return true;
}

bool shouldUseFloatCall(const std::vector<FriendScalar> &args)
{
    for (const auto &arg : args) {
        if (arg.type == SimpleType::Float) return true;
    }
    return false;
}

double toDoubleArg(const FriendScalar &value)
{
    if (value.type == SimpleType::Float) return value.floatValue;
    if (value.type == SimpleType::Bool) return value.intValue ? 1.0 : 0.0;
    return static_cast<double>(value.intValue);
}

int toIntArg(const FriendScalar &value)
{
    if (value.type == SimpleType::Bool) return value.intValue ? 1 : 0;
    if (value.type == SimpleType::Float) return static_cast<int>(value.floatValue);
    return static_cast<int>(value.intValue);
}

bool invokeDoubleSymbol(void *symbol,
                        const std::vector<double> &args,
                        double &result,
                        std::string &errorMessage)
{
    if (args.size() > kMaxFriendCallArgs) {
        errorMessage = tooManyArgumentsMessage();
        return false;
    }
    result = kDoubleInvokers[args.size()](symbol, args);
    return true;
}

bool invokeIntSymbol(void *symbol,
                     const std::vector<int> &args,
                     int &result,
                     std::string &errorMessage)
{
    if (args.size() > kMaxFriendCallArgs) {
        errorMessage = tooManyArgumentsMessage();
        return false;
    }
    result = kIntInvokers[args.size()](symbol, args);
    return true;
}

} // namespace FriendTranslation
