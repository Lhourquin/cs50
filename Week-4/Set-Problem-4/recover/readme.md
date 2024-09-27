## JPEGs

* Each JPEG starts with a distinct header
  * First Three Bytes: `0xff 0xd8 0xff`
  * Last Bytes: `0xe0, 0xe1, 0xe2, ..., 0xef etc`
* **JPEGs stored back-to-back in memory card**
* Each block is 512 bytes
