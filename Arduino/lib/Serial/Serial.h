#ifndef SERIAL_H
#define SERIAL_H

#define endl "\r\n"

template<class T>
inline Print &operator <<(Print &obj, T arg) { obj.print(arg); return obj; }


#endif
