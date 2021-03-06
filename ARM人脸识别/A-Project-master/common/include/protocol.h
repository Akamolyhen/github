#ifndef _PROTOCOL_H_
#define _PROTOCOL_H_

#include "ringbuffer.h"
#include "type.h"

#define PROTO_HEAD_OFFSET		0
#define PROTO_VERIFY_OFFSET		(PROTO_HEAD_OFFSET +1)
#define PROTO_SEQ_OFFSET		(PROTO_VERIFY_OFFSET +4)
#define PROTO_CMD_OFFSET		(PROTO_SEQ_OFFSET +1)
#define PROTO_LEN_OFFSET		(PROTO_CMD_OFFSET +1)
#define PROTO_DATA_OFFSET		(PROTO_LEN_OFFSET +4)

#define PROTO_PACK_MAX_LEN		(1 *1024 *1024)
#define PROTO_PACK_MIN_LEN		(PROTO_DATA_OFFSET +1)

#define PROTO_HEAD		0xFF
#define PROTO_TAIL		0xFE
#define PROTO_VERIFY	"ABCD"

/* protocol packet direction type */
typedef enum
{
	PROTO_REQ = 0,
	PROTO_ACK = 1,
}ePacket_t;

struct detect_info
{
	char head;
	char verify;
	char tail;
	int len;
	int pack_len;
};

typedef int (*send_func_t)(int fd, uint8_t *data, int len);

struct proto_object
{
	int used;
	int fd;
	send_func_t send_func;
	uint8_t	*send_buf;
	int buf_size;
};


struct Rect_params
{
	int x;
	int y;
	int w;
	int h;
};

int proto_0x03_dataAnaly(uint8_t *data, int len, ePacket_t type, void *a, void *b);
int proto_0x03_sendHeartBeat(int handle);

int proto_0x10_getOneFrame(int handle);
int proto_0x11_sendFaceDetect(int handle, uint8_t count, struct Rect_params *face_rect);
int proto_0x12_sendFaceRecogn(int handle, int face_id, char *face_name);

int proto_makeupPacket(uint8_t seq, uint8_t cmd, int len, uint8_t *data, \
								uint8_t *outbuf, int size, int *outlen);
int proto_analyPacket(uint8_t *pack, int packLen, uint8_t *seq, \
								uint8_t *cmd, int *len, uint8_t **data);
int proto_detectPack(struct ringbuffer *ringbuf, struct detect_info *detect, \
								uint8_t *proto_data, int size, int *proto_len);
int proto_register(int fd, send_func_t send_func, int buf_size);
void proto_unregister(int handle);
int proto_init(void);


#endif	// _PROTOCOL_H_
