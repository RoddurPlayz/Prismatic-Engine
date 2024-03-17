#include "../GLFW/glfw3.h"


// Display

#define PRISMmonitor                 GLFWmonitor
#define PRISMvidmode                 GLFWvidmode

// Events

#define PRISMevent                   int

#define PRSIM_RELEASE                0

#define PRSIM_PRESS                  1

#define PRSIM_REPEAT                 2

#define PRISM_HAT_CENTERED           0
#define PRISM_HAT_UP                 1
#define PRISM_HAT_RIGHT              2
#define PRISM_HAT_DOWN               4
#define PRISM_HAT_LEFT               8
#define PRISM_HAT_RIGHT_UP           (GLFW_HAT_RIGHT | GLFW_HAT_UP)
#define PRISM_HAT_RIGHT_DOWN         (GLFW_HAT_RIGHT | GLFW_HAT_DOWN)
#define PRISM_HAT_LEFT_UP            (GLFW_HAT_LEFT  | GLFW_HAT_UP)
#define PRISM_HAT_LEFT_DOWN          (GLFW_HAT_LEFT  | GLFW_HAT_DOWN)

#define PRISM_KEY_UNKNOWN            -1

#define PRISM_KEY_SPACE              32
#define PRISM_KEY_APOSTROPHE         39
#define PRISM_KEY_COMMA              44
#define PRISM_KEY_MINUS              45
#define PRISM_KEY_PERIOD             46
#define PRISM_KEY_SLASH              47
#define PRISM_KEY_0                  48
#define PRISM_KEY_1                  49
#define PRISM_KEY_2                  50
#define PRISM_KEY_3                  51
#define PRISM_KEY_4                  52
#define PRISM_KEY_5                  53
#define PRISM_KEY_6                  54
#define PRISM_KEY_7                  55
#define PRISM_KEY_8                  56
#define PRISM_KEY_9                  57
#define PRISM_KEY_SEMICOLON          59
#define PRISM_KEY_EQUAL              61
#define PRISM_KEY_A                  65
#define PRISM_KEY_B                  66
#define PRISM_KEY_C                  67
#define PRISM_KEY_D                  68
#define PRISM_KEY_E                  69
#define PRISM_KEY_F                  70
#define PRISM_KEY_G                  71
#define PRISM_KEY_H                  72
#define PRISM_KEY_I                  73
#define PRISM_KEY_J                  74
#define PRISM_KEY_K                  75
#define PRISM_KEY_L                  76
#define PRISM_KEY_M                  77
#define PRISM_KEY_N                  78
#define PRISM_KEY_O                  79
#define PRISM_KEY_P                  80
#define PRISM_KEY_Q                  81
#define PRISM_KEY_R                  82
#define PRISM_KEY_S                  83
#define PRISM_KEY_T                  84
#define PRISM_KEY_U                  85
#define PRISM_KEY_V                  86
#define PRISM_KEY_W                  87
#define PRISM_KEY_X                  88
#define PRISM_KEY_Y                  89
#define PRISM_KEY_Z                  90
#define PRISM_KEY_LEFT_BRACKET       91
#define PRISM_KEY_BACKSLASH          92
#define PRISM_KEY_RIGHT_BRACKET      93
#define PRISM_KEY_GRAVE_ACCENT       96
#define PRISM_KEY_WORLD_1            161
#define PRISM_KEY_WORLD_2            162

#define PRISM_KEY_ESCAPE             256
#define PRISM_KEY_ENTER              257
#define PRISM_KEY_TAB                258
#define PRISM_KEY_BACKSPACE          259
#define PRISM_KEY_INSERT             260
#define PRISM_KEY_DELETE             261
#define PRISM_KEY_RIGHT              262
#define PRISM_KEY_LEFT               263
#define PRISM_KEY_DOWN               264
#define PRISM_KEY_UP                 265
#define PRISM_KEY_PAGE_UP            266
#define PRISM_KEY_PAGE_DOWN          267
#define PRISM_KEY_HOME               268
#define PRISM_KEY_END                269
#define PRISM_KEY_CAPS_LOCK          280
#define PRISM_KEY_SCROLL_LOCK        281
#define PRISM_KEY_NUM_LOCK           282
#define PRISM_KEY_PRINT_SCREEN       283
#define PRISM_KEY_PAUSE              284
#define PRISM_KEY_F1                 290
#define PRISM_KEY_F2                 291
#define PRISM_KEY_F3                 292
#define PRISM_KEY_F4                 293
#define PRISM_KEY_F5                 294
#define PRISM_KEY_F6                 295
#define PRISM_KEY_F7                 296
#define PRISM_KEY_F8                 297
#define PRISM_KEY_F9                 298
#define PRISM_KEY_F10                299
#define PRISM_KEY_F11                300
#define PRISM_KEY_F12                301
#define PRISM_KEY_F13                302
#define PRISM_KEY_F14                303
#define PRISM_KEY_F15                304
#define PRISM_KEY_F16                305
#define PRISM_KEY_F17                306
#define PRISM_KEY_F18                307
#define PRISM_KEY_F19                308
#define PRISM_KEY_F20                309
#define PRISM_KEY_F21                310
#define PRISM_KEY_F22                311
#define PRISM_KEY_F23                312
#define PRISM_KEY_F24                313
#define PRISM_KEY_F25                314
#define PRISM_KEY_KP_0               320
#define PRISM_KEY_KP_1               321
#define PRISM_KEY_KP_2               322
#define PRISM_KEY_KP_3               323
#define PRISM_KEY_KP_4               324
#define PRISM_KEY_KP_5               325
#define PRISM_KEY_KP_6               326
#define PRISM_KEY_KP_7               327
#define PRISM_KEY_KP_8               328
#define PRISM_KEY_KP_9               329
#define PRISM_KEY_KP_DECIMAL         330
#define PRISM_KEY_KP_DIVIDE          331
#define PRISM_KEY_KP_MULTIPLY        332
#define PRISM_KEY_KP_SUBTRACT        333
#define PRISM_KEY_KP_ADD             334
#define PRISM_KEY_KP_ENTER           335
#define PRISM_KEY_KP_EQUAL           336
#define PRISM_KEY_LEFT_SHIFT         340
#define PRISM_KEY_LEFT_CONTROL       341
#define PRISM_KEY_LEFT_ALT           342
#define PRISM_KEY_LEFT_SUPER         343
#define PRISM_KEY_RIGHT_SHIFT        344
#define PRISM_KEY_RIGHT_CONTROL      345
#define PRISM_KEY_RIGHT_ALT          346
#define PRISM_KEY_RIGHT_SUPER        347
#define PRISM_KEY_MENU               348

#define PRISM_KEY_LAST               GLFW_KEY_MENU

#define PRISM_MOD_SHIFT           0x0001

#define PRISM_MOD_CONTROL         0x0002

#define PRISM_MOD_ALT             0x0004

#define PRISM_MOD_SUPER           0x0008

#define PRISM_MOD_CAPS_LOCK       0x0010

#define PRISM_MOD_NUM_LOCK        0x0020

#define PRISM_MOUSE_BUTTON_1         0
#define PRISM_MOUSE_BUTTON_2         1
#define PRISM_MOUSE_BUTTON_3         2
#define PRISM_MOUSE_BUTTON_4         3
#define PRISM_MOUSE_BUTTON_5         4
#define PRISM_MOUSE_BUTTON_6         5
#define PRISM_MOUSE_BUTTON_7         6
#define PRISM_MOUSE_BUTTON_8         7
#define PRISM_MOUSE_BUTTON_LAST      PRISM_MOUSE_BUTTON_8
#define PRISM_MOUSE_BUTTON_LEFT      PRISM_MOUSE_BUTTON_1
#define PRISM_MOUSE_BUTTON_RIGHT     PRISM_MOUSE_BUTTON_2
#define PRISM_MOUSE_BUTTON_MIDDLE    PRISM_MOUSE_BUTTON_3

#define PRISM_JOYSTICK_1             0
#define PRISM_JOYSTICK_2             1
#define PRISM_JOYSTICK_3             2
#define PRISM_JOYSTICK_4             3
#define PRISM_JOYSTICK_5             4
#define PRISM_JOYSTICK_6             5
#define PRISM_JOYSTICK_7             6
#define PRISM_JOYSTICK_8             7
#define PRISM_JOYSTICK_9             8
#define PRISM_JOYSTICK_10            9
#define PRISM_JOYSTICK_11            10
#define PRISM_JOYSTICK_12            11
#define PRISM_JOYSTICK_13            12
#define PRISM_JOYSTICK_14            13
#define PRISM_JOYSTICK_15            14
#define PRISM_JOYSTICK_16            15
#define PRISM_JOYSTICK_LAST          PRISM_JOYSTICK_16

#define PRISM_GAMEPAD_BUTTON_A               0
#define PRISM_GAMEPAD_BUTTON_B               1
#define PRISM_GAMEPAD_BUTTON_X               2
#define PRISM_GAMEPAD_BUTTON_Y               3
#define PRISM_GAMEPAD_BUTTON_LEFT_BUMPER     4
#define PRISM_GAMEPAD_BUTTON_RIGHT_BUMPER    5
#define PRISM_GAMEPAD_BUTTON_BACK            6
#define PRISM_GAMEPAD_BUTTON_START           7
#define PRISM_GAMEPAD_BUTTON_GUIDE           8
#define PRISM_GAMEPAD_BUTTON_LEFT_THUMB      9
#define PRISM_GAMEPAD_BUTTON_RIGHT_THUMB     10
#define PRISM_GAMEPAD_BUTTON_DPAD_UP         11
#define PRISM_GAMEPAD_BUTTON_DPAD_RIGHT      12
#define PRISM_GAMEPAD_BUTTON_DPAD_DOWN       13
#define PRISM_GAMEPAD_BUTTON_DPAD_LEFT       14
#define PRISM_GAMEPAD_BUTTON_LAST            PRISM_GAMEPAD_BUTTON_DPAD_LEFT

#define PRISM_GAMEPAD_BUTTON_CROSS       PRISM_GAMEPAD_BUTTON_A
#define PRISM_GAMEPAD_BUTTON_CIRCLE      PRISM_GAMEPAD_BUTTON_B
#define PRISM_GAMEPAD_BUTTON_SQUARE      PRISM_GAMEPAD_BUTTON_X
#define PRISM_GAMEPAD_BUTTON_TRIANGLE    PRISM_GAMEPAD_BUTTON_Y

#define PRISM_GAMEPAD_AXIS_LEFT_X        0
#define PRISM_GAMEPAD_AXIS_LEFT_Y        1
#define PRISM_GAMEPAD_AXIS_RIGHT_X       2
#define PRISM_GAMEPAD_AXIS_RIGHT_Y       3
#define PRISM_GAMEPAD_AXIS_LEFT_TRIGGER  4
#define PRISM_GAMEPAD_AXIS_RIGHT_TRIGGER 5
#define PRISM_GAMEPAD_AXIS_LAST          PRISM_GAMEPAD_AXIS_RIGHT_TRIGGER
