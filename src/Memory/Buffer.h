#ifndef _Buffer_h_
#define _Buffer_h_

#include <cstddef>

template <typename T> class Vector2;
typedef Vector2<float> Vector2f;

class Color;

class Buffer
{
    protected:
        char* data;
        size_t length;
        char* bufferEnd;

        char* readLoc;
        char* writeLoc;

        bool external;

    public:
        Buffer();
        Buffer(size_t maxSize);
        Buffer(char* buf, int bufferLength);

        virtual ~Buffer();

        void allocateData(size_t maxSize);
        void setBuffer(char* buf, int bufferLength);

        bool atEnd();
        size_t size();

        void rewind();
        void move(int offset);
        void clear();

        void append(Buffer* b);

        char* getData();

        void setWriteLoc(int count, size_t bytesPerCount);
        void setReadLoc(int count, size_t bytesPerCount);
        template<class T> void setWriteLoc(int count)
        {
            writeLoc = data + sizeof(T) * count;
        }
        template<class T> void setReadLoc(int count)
        {
            readLoc = data + sizeof(T) * count;
        }

        // used for making display lists that will pass these buffers directly to OpenGL;  no converting into global endianness!
        //void writeUint16Native(uint16 value);

        float readFloat();
        void writeFloat(float value);

        void readVector(Vector2f* v);
        void writeVector(float x, float y);
        void writeVector(const Vector2f& v);

        void readColor(Color* c);
        void writeColor(float r, float g, float b, float a);
        void writeColor(const Color& c);

        void dumpBuffer();
};

#endif

