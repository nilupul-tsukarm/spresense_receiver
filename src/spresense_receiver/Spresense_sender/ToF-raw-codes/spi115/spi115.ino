#include <SPI.h>

void setup() {
    Serial.begin(115200);
    SPI5.begin();
  SPI5.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE3));
}

void loop() {
  static  char  buf[256] = {0};
  static  int bufpos = 0;
  static  int c0 = -1;
  int i, c;
  
  if ((c = Serial.read()) < 0)
    return;
  if ((c >= '0')&&(c <= '9')) {
    i = c - '0';
    if (c0 < 0)
      c0 = i << 4;
    else {
      if (bufpos < sizeof(buf))
        buf[bufpos++] = c0 | i;
      c0 = -1;
    }
    return;
  }
  if ((c >= 'A')&&(c <= 'F')) {
    i = c - 'A' + 0xa;
    if (c0 < 0)
      c0 = i << 4;
    else {
      if (bufpos < sizeof(buf))
        buf[bufpos++] = c0 | i;
      c0 = -1;
    }
    return;
  }
  if ((c >= 'a')&&(c <= 'f')) {
    i = c - 'a' + 0xa;
    if (c0 < 0)
      c0 = i << 4;
    else {
      if (bufpos < sizeof(buf))
        buf[bufpos++] = c0 | i;
      c0 = -1;
    }
    return;
  }
  if (c < 0x20) {
    c0 = -1;
    if (bufpos > 0) {
      for (i=bufpos; i<sizeof(buf); i++)
        buf[i] = 0;
      bufpos = 0;
    }
  }
  for (i=0; i<sizeof(buf); i++) {
    static  const char  *bin2hex = "0123456789abcdef";
    static  char  s[] = {0, 0, 0x20, 0};
    int c = SPI5.transfer(buf[i]);
    s[0] = bin2hex[(c >> 4) & 0xf];
    s[1] = bin2hex[c & 0xf];
    Serial.print(s);
  }
  Serial.print("\r\n");
}
