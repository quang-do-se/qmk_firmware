#pragma once

enum layers {
    _BASE,
    _FUNCTION,
    _RGB,
    _SWITCH,
    _LAST
};

const char* layerNames [] = {
    [_BASE] = "Base",
    [_FUNCTION] = "Function",
    [_RGB] = "RGB",
    [_SWITCH] = "Switch"
};
