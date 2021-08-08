#ifndef _SAPPHIREENGINE_INPUTDEVICE_KEYCODE_H
#define _SAPPHIREENGINE_INPUTDEVICE_KEYCODE_H

namespace SapphireEngine::InputDevice
{
    enum class KeyCode : int
    {
        num0 = 48,
        num1, num2, num3, num4, num5,
        num6, num7, num8, num9 = 57,

        A = 65,
        B, C, D, E, F,
        G, H, I, J, K,
        L, M, N, O, P,
        Q, R, S, T, U,
        V, W, X, Y, Z = 90,

        Space = 32,

        Apostrophe = 39, /* ' */
        Comma = 44,		 /* , */
        Minus = 45,		 /* - */
        Period = 46,	 /* . */
        Slash = 47,		 /* / */
        Semicolon = 59,  /* ; */
        Equal = 61,	     /* = */

        LeftBrracket = 91, /* [ */
        BackSlash = 92, /* \ */
        RightBracket = 93, /* ] */
        GraveAccent = 96, /* ` */

        keypadNum0 = 320,
        keypadNum1, keypadNum2, keypadNum3,
        keypadNum4, keypadNum5, keypadNum6,
        keypadNum7, keypadNum8, keypadNum9 = 329,

        Escape = 256,
        Enter = 257,
        Tab = 258,
        Backspace = 259,
        Insert = 260,
        Delete = 261,
        Right = 262,
        Left = 263,
        Down = 264,
        Up = 265,
        Page_Up = 266,
        Page_Down = 267,
        Home = 268,
        End = 269,
        CapsLock = 280,
        ScrollLock = 281,
        NumLock = 282,
        PrintScreen = 283,
        Pause = 284,


        F1 = 290,
        F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, F13, F14, F15 = 304,

        KP_Decimal = 330,
        KP_Divided = 331,
        KP_Multiply = 332,
        KP_Subtract = 333,
        KP_Add = 334,
        KP_Enter = 335,
        KP_Equal = 336,
        LEFT_SHIFT = 340,
        LeftControl = 341,
        LeftAlt = 342,
        LeftSuper = 343,
        RightShift = 344,
        RightControl = 345,
        RightAlt = 346,
        RightSuper = 347,
        Menu = 348,
    };
}

#endif // !SAPPHIREENGINE_INPUTDEVICE_KEYCODE_H
