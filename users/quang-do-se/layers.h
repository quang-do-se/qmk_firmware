#pragma once

enum layers {
    _BASE,
    _RGB,
    _ENTERTAINMENT,
    _SWITCH,
    _FUNCTION,
    _LAST
};

const char* layerNames [] = {
    [_BASE] = "Base",
    [_RGB] = "RGB",
    [_ENTERTAINMENT] = "Entertainment",
    [_SWITCH] = "Switch",
    [_FUNCTION] = "Function",
};

// When you press a key, QMK goes looking through the stack of layers, starting at the top: the layer with the highest number.
// Layers with higher number has the priorty.
