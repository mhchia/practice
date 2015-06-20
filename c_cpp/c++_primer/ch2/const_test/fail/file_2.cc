// const objects are local to a file by default.
// Thus, it is not visible other .o file even though they declared that variable
// e.g. extern int bufSize;
const int bufSize = 512;
