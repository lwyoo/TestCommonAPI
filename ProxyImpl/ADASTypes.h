#ifndef ADASTYPES_H
#define ADASTYPES_H
enum class ADAS_GL_STATE {
    ADAS_GL_NONE = 0, /* The Input is invalid */
    ADAS_GL_INIT,
    ADAS_GL_READ,
    ADAS_GL_ON,
    ADAS_GL_OFF,
    ADAS_GL_DRAWING,
    ADAS_GL_DRAW_COMPLETE,
    ADAS_GL_MAX
};

#endif // ADASTYPES_H
