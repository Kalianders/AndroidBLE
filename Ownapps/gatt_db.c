#include <stdint.h>
#include "ubt/bg_gattdb_def.h"

#ifdef __GNUC__
#define GATT_HEADER(F) F __attribute__ ((section (".gatt_header"))) 
#define GATT_DATA(F) F __attribute__ ((section (".gatt_data"))) 
#else
#ifdef __ICCARM__
#define GATT_HEADER(F) _Pragma("location=\".gatt_header\"") F 
#define GATT_DATA(F) _Pragma("location=\".gatt_data\"") F 
#else
#define GATT_HEADER(F) F 
#define GATT_DATA(F) F 
#endif
#endif

GATT_DATA(const uint16_t bg_gattdb_uuidtable_16_map [])=
{
    0x2800,
    0x2801,
    0x2803,
    0x1800,
    0x2a00,
    0x2a01,
    0x180a,
    0x2a29,
    0x2a24,
    0x2a23,
    0x1803,
    0x2a06,
    0x1802,
    0x1804,
    0x2a07,
    0x2901,
    0x2902,
};

GATT_DATA(const uint8_t bg_gattdb_uuidtable_128_map [])=
{
0xd1, 0x8c, 0x46, 0x39, 0x7a, 0xbd, 0xe6, 0xa7, 0x54, 0x48, 0xc1, 0xe7, 0x7d, 0xc9, 0x69, 0x0e, 
0x65, 0xd0, 0x4f, 0xb1, 0xc4, 0xb7, 0x62, 0xa5, 0xb9, 0x4b, 0xc2, 0x8a, 0xe9, 0xec, 0xb9, 0x82, 
};




GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_25 ) = {
	.len=12,
	.data={0x56,0x6f,0x6c,0x74,0x61,0x67,0x65,0x20,0x28,0x6d,0x56,0x29,}
};
uint8_t bg_gattdb_attribute_field_23_data[2]={0x00,0x00,};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_attribute_field_23 ) = {
	.properties=0x12,
	.index=3,
	.max_len=2,
	.data=bg_gattdb_attribute_field_23_data,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_22 ) = {
	.len=19,
	.data={0x12,0x18,0x00,0x65,0xd0,0x4f,0xb1,0xc4,0xb7,0x62,0xa5,0xb9,0x4b,0xc2,0x8a,0xe9,0xec,0xb9,0x82,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_21 ) = {
	.len=16,
	.data={0xd1,0x8c,0x46,0x39,0x7a,0xbd,0xe6,0xa7,0x54,0x48,0xc1,0xe7,0x7d,0xc9,0x69,0x0e,}
};
uint8_t bg_gattdb_attribute_field_20_data[1]={0x00,};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_attribute_field_20 ) = {
	.properties=0x02,
	.index=2,
	.max_len=1,
	.data=bg_gattdb_attribute_field_20_data,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_19 ) = {
	.len=5,
	.data={0x02,0x15,0x00,0x07,0x2a,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_18 ) = {
	.len=2,
	.data={0x04,0x18,}
};
uint8_t bg_gattdb_attribute_field_17_data[1]={0x00,};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_attribute_field_17 ) = {
	.properties=0x04,
	.index=1,
	.max_len=1,
	.data=bg_gattdb_attribute_field_17_data,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_16 ) = {
	.len=5,
	.data={0x04,0x12,0x00,0x06,0x2a,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_15 ) = {
	.len=2,
	.data={0x02,0x18,}
};
uint8_t bg_gattdb_attribute_field_14_data[1]={0x00,};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_attribute_field_14 ) = {
	.properties=0x0a,
	.index=0,
	.max_len=1,
	.data=bg_gattdb_attribute_field_14_data,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_13 ) = {
	.len=5,
	.data={0x0a,0x0f,0x00,0x06,0x2a,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_12 ) = {
	.len=2,
	.data={0x03,0x18,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_11 ) = {
	.len=6,
	.data={0x00,0x07,0x80,0x00,0x00,0x47,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_10 ) = {
	.len=5,
	.data={0x02,0x0c,0x00,0x23,0x2a,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_9 ) = {
	.len=6,
	.data={0x42,0x47,0x4d,0x31,0x31,0x31,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_8 ) = {
	.len=5,
	.data={0x02,0x0a,0x00,0x24,0x2a,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_7 ) = {
	.len=12,
	.data={0x53,0x69,0x6c,0x69,0x63,0x6f,0x6e,0x20,0x4c,0x61,0x62,0x73,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_6 ) = {
	.len=5,
	.data={0x02,0x08,0x00,0x29,0x2a,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_5 ) = {
	.len=2,
	.data={0x0a,0x18,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_4 ) = {
	.len=2,
	.data={0x01,0x28,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_3 ) = {
	.len=5,
	.data={0x02,0x05,0x00,0x01,0x2a,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_2 ) = {
	.len=4,
	.data={0x54,0x45,0x53,0x54,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_1 ) = {
	.len=5,
	.data={0x02,0x03,0x00,0x00,0x2a,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_0 ) = {
	.len=2,
	.data={0x00,0x18,}
};
GATT_DATA(const struct bg_gattdb_attribute bg_gattdb_attributes_map[])={
    {.uuid=0x0000,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_0},
    {.uuid=0x0002,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_1},
    {.uuid=0x0004,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_2},
    {.uuid=0x0002,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_3},
    {.uuid=0x0005,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_4},
    {.uuid=0x0000,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_5},
    {.uuid=0x0002,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_6},
    {.uuid=0x0007,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_7},
    {.uuid=0x0002,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_8},
    {.uuid=0x0008,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_9},
    {.uuid=0x0002,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_10},
    {.uuid=0x0009,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_11},
    {.uuid=0x0000,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_12},
    {.uuid=0x0002,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_13},
    {.uuid=0x000b,.permissions=0x03,.datatype=0x01,.min_key_size=0x00,.dynamicdata=&bg_gattdb_attribute_field_14},
    {.uuid=0x0000,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_15},
    {.uuid=0x0002,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_16},
    {.uuid=0x000b,.permissions=0x04,.datatype=0x01,.min_key_size=0x00,.dynamicdata=&bg_gattdb_attribute_field_17},
    {.uuid=0x0000,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_18},
    {.uuid=0x0002,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_19},
    {.uuid=0x000e,.permissions=0x01,.datatype=0x01,.min_key_size=0x00,.dynamicdata=&bg_gattdb_attribute_field_20},
    {.uuid=0x0000,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_21},
    {.uuid=0x0002,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_22},
    {.uuid=0x8001,.permissions=0x01,.datatype=0x01,.min_key_size=0x00,.dynamicdata=&bg_gattdb_attribute_field_23},
    {.uuid=0x0010,.permissions=0x07,.datatype=0x03,.min_key_size=0x00,.configdata={.flags=0x01,.index=0x03}},
    {.uuid=0x000f,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_25},
};

GATT_DATA(const uint16_t bg_gattdb_attributes_dynamic_mapping_map[])={
	0x000f,
	0x0012,
	0x0015,
	0x0018,
};

GATT_DATA(const uint8_t bg_gattdb_adv_uuid16_map[])={0x03, 0x18, 0x02, 0x18, 0x04, 0x18, };
GATT_DATA(const uint8_t bg_gattdb_adv_uuid128_map[])={0xd1, 0x8c, 0x46, 0x39, 0x7a, 0xbd, 0xe6, 0xa7, 0x54, 0x48, 0xc1, 0xe7, 0x7d, 0xc9, 0x69, 0x0e, };
GATT_HEADER(const struct bg_gattdb_def bg_gattdb_data )={
    .attributes=bg_gattdb_attributes_map,
    .attributes_max=26,
    .uuidtable_16_size=17,
    .uuidtable_16=bg_gattdb_uuidtable_16_map,
    .uuidtable_128_size=2,
    .uuidtable_128=bg_gattdb_uuidtable_128_map,
    .attributes_dynamic_max=4,
    .attributes_dynamic_mapping=bg_gattdb_attributes_dynamic_mapping_map,
    .adv_uuid16=bg_gattdb_adv_uuid16_map,
    .adv_uuid16_num=3,
    .adv_uuid128=bg_gattdb_adv_uuid128_map,
    .adv_uuid128_num=1,
};

const struct bg_gattdb_def *bg_gattdb=&bg_gattdb_data;
