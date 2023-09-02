#pragma once

enum layers {
    _BASE,
    _FUNCTION,
    _SWITCH,
    _LAST
};

const char* layerNames [] = {
    [_BASE] = "Base",
    [_FUNCTION] = "Function",
    [_SWITCH] = "Switch"
};
