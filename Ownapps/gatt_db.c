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
    0x2901,
    0x2902,
};

GATT_DATA(const uint8_t bg_gattdb_uuidtable_128_map [])=
{
0xb9, 0x54, 0xb7, 0xce, 0x73, 0x4f, 0x8d, 0xa6, 0xcf, 0x4e, 0x39, 0x6b, 0xa7, 0x82, 0xc2, 0x2b, 
0x02, 0x03, 0xf0, 0xc8, 0x6f, 0x04, 0x27, 0x95, 0x72, 0x4f, 0x39, 0x0d, 0xbc, 0x57, 0xca, 0x91, 
0x99, 0x70, 0xe0, 0x56, 0x2f, 0xb8, 0xbf, 0xae, 0xf7, 0x4a, 0xae, 0x2e, 0x7f, 0xac, 0xe6, 0xa6, 
0xd9, 0xe3, 0x11, 0xc4, 0x72, 0x05, 0xf6, 0x9d, 0x5e, 0x45, 0xd9, 0x50, 0x31, 0xcf, 0x99, 0x11, 
0xf9, 0x52, 0x7a, 0xc8, 0xb8, 0x95, 0x07, 0x86, 0xdd, 0x46, 0x5e, 0xd4, 0x36, 0x6a, 0xc4, 0xa8, 
0x9c, 0x31, 0xc5, 0xde, 0x2d, 0x76, 0xf4, 0xaa, 0xea, 0x4e, 0xe3, 0x63, 0x08, 0xf4, 0x09, 0x84, 
0x6b, 0x24, 0x03, 0x62, 0x57, 0x5b, 0xc6, 0xb5, 0x92, 0x48, 0xe7, 0xae, 0x08, 0x2b, 0x40, 0xc5, 
0x6e, 0xdf, 0xe3, 0xfb, 0x3c, 0xb6, 0xfa, 0x9a, 0xf9, 0x4d, 0xac, 0xa5, 0x02, 0x91, 0xde, 0x53, 
};




GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_28 ) = {
	.len=13,
	.data={0x53,0x74,0x61,0x74,0x75,0x73,0x20,0x76,0x65,0x63,0x74,0x6f,0x72,}
};
uint8_t bg_gattdb_attribute_field_26_data[21];
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_attribute_field_26 ) = {
	.properties=0x10,
	.index=5,
	.max_len=20,
	.data_varlen=(struct bg_gattdb_buffer_with_len*)bg_gattdb_attribute_field_26_data,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_25 ) = {
	.len=19,
	.data={0x10,0x1b,0x00,0x6e,0xdf,0xe3,0xfb,0x3c,0xb6,0xfa,0x9a,0xf9,0x4d,0xac,0xa5,0x02,0x91,0xde,0x53,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_24 ) = {
	.len=12,
	.data={0x43,0x6f,0x6e,0x74,0x72,0x6f,0x6c,0x20,0x62,0x79,0x74,0x65,}
};
uint8_t bg_gattdb_attribute_field_23_data[1]={0x00,};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_attribute_field_23 ) = {
	.properties=0x0a,
	.index=4,
	.max_len=1,
	.data=bg_gattdb_attribute_field_23_data,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_22 ) = {
	.len=19,
	.data={0x0a,0x18,0x00,0x6b,0x24,0x03,0x62,0x57,0x5b,0xc6,0xb5,0x92,0x48,0xe7,0xae,0x08,0x2b,0x40,0xc5,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_21 ) = {
	.len=16,
	.data={0x9c,0x31,0xc5,0xde,0x2d,0x76,0xf4,0xaa,0xea,0x4e,0xe3,0x63,0x08,0xf4,0x09,0x84,}
};
uint8_t bg_gattdb_attribute_field_20_data[1]={0x00,};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_attribute_field_20 ) = {
	.properties=0x0a,
	.index=3,
	.max_len=1,
	.data=bg_gattdb_attribute_field_20_data,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_19 ) = {
	.len=19,
	.data={0x0a,0x15,0x00,0xf9,0x52,0x7a,0xc8,0xb8,0x95,0x07,0x86,0xdd,0x46,0x5e,0xd4,0x36,0x6a,0xc4,0xa8,}
};
uint8_t bg_gattdb_attribute_field_18_data[1]={0x00,};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_attribute_field_18 ) = {
	.properties=0x0a,
	.index=2,
	.max_len=1,
	.data=bg_gattdb_attribute_field_18_data,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_17 ) = {
	.len=19,
	.data={0x0a,0x13,0x00,0xd9,0xe3,0x11,0xc4,0x72,0x05,0xf6,0x9d,0x5e,0x45,0xd9,0x50,0x31,0xcf,0x99,0x11,}
};
uint8_t bg_gattdb_attribute_field_16_data[1]={0x00,};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_attribute_field_16 ) = {
	.properties=0x0a,
	.index=1,
	.max_len=1,
	.data=bg_gattdb_attribute_field_16_data,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_15 ) = {
	.len=19,
	.data={0x0a,0x11,0x00,0x99,0x70,0xe0,0x56,0x2f,0xb8,0xbf,0xae,0xf7,0x4a,0xae,0x2e,0x7f,0xac,0xe6,0xa6,}
};
uint8_t bg_gattdb_attribute_field_14_data[1]={0x00,};
GATT_DATA(const struct bg_gattdb_attribute_chrvalue	bg_gattdb_attribute_field_14 ) = {
	.properties=0x0a,
	.index=0,
	.max_len=1,
	.data=bg_gattdb_attribute_field_14_data,
};

GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_13 ) = {
	.len=19,
	.data={0x0a,0x0f,0x00,0x02,0x03,0xf0,0xc8,0x6f,0x04,0x27,0x95,0x72,0x4f,0x39,0x0d,0xbc,0x57,0xca,0x91,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_12 ) = {
	.len=16,
	.data={0xb9,0x54,0xb7,0xce,0x73,0x4f,0x8d,0xa6,0xcf,0x4e,0x39,0x6b,0xa7,0x82,0xc2,0x2b,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_11 ) = {
	.len=5,
	.data={0x01,0x61,0x61,0x41,0x38,}
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
	.data={0x03,0x84,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_3 ) = {
	.len=5,
	.data={0x02,0x05,0x00,0x01,0x2a,}
};
GATT_DATA(const struct bg_gattdb_buffer_with_len	bg_gattdb_attribute_field_2 ) = {
	.len=5,
	.data={0x74,0x65,0x73,0x74,0x69,}
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
    {.uuid=0x8001,.permissions=0x03,.datatype=0x01,.min_key_size=0x00,.dynamicdata=&bg_gattdb_attribute_field_14},
    {.uuid=0x0002,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_15},
    {.uuid=0x8002,.permissions=0x03,.datatype=0x01,.min_key_size=0x00,.dynamicdata=&bg_gattdb_attribute_field_16},
    {.uuid=0x0002,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_17},
    {.uuid=0x8003,.permissions=0x03,.datatype=0x01,.min_key_size=0x00,.dynamicdata=&bg_gattdb_attribute_field_18},
    {.uuid=0x0002,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_19},
    {.uuid=0x8004,.permissions=0x03,.datatype=0x01,.min_key_size=0x00,.dynamicdata=&bg_gattdb_attribute_field_20},
    {.uuid=0x0000,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_21},
    {.uuid=0x0002,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_22},
    {.uuid=0x8006,.permissions=0x03,.datatype=0x01,.min_key_size=0x00,.dynamicdata=&bg_gattdb_attribute_field_23},
    {.uuid=0x000a,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_24},
    {.uuid=0x0002,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_25},
    {.uuid=0x8007,.permissions=0x00,.datatype=0x02,.min_key_size=0x00,.dynamicdata=&bg_gattdb_attribute_field_26},
    {.uuid=0x000b,.permissions=0x07,.datatype=0x03,.min_key_size=0x00,.configdata={.flags=0x01,.index=0x05}},
    {.uuid=0x000a,.permissions=0x01,.datatype=0x00,.min_key_size=0x00,.constdata=&bg_gattdb_attribute_field_28},
};

GATT_DATA(const uint16_t bg_gattdb_attributes_dynamic_mapping_map[])={
	0x000f,
	0x0011,
	0x0013,
	0x0015,
	0x0018,
	0x001b,
};

GATT_DATA(const uint8_t bg_gattdb_adv_uuid16_map[])={0x0};
GATT_DATA(const uint8_t bg_gattdb_adv_uuid128_map[])={0xb9, 0x54, 0xb7, 0xce, 0x73, 0x4f, 0x8d, 0xa6, 0xcf, 0x4e, 0x39, 0x6b, 0xa7, 0x82, 0xc2, 0x2b, };
GATT_HEADER(const struct bg_gattdb_def bg_gattdb_data )={
    .attributes=bg_gattdb_attributes_map,
    .attributes_max=29,
    .uuidtable_16_size=12,
    .uuidtable_16=bg_gattdb_uuidtable_16_map,
    .uuidtable_128_size=8,
    .uuidtable_128=bg_gattdb_uuidtable_128_map,
    .attributes_dynamic_max=6,
    .attributes_dynamic_mapping=bg_gattdb_attributes_dynamic_mapping_map,
    .adv_uuid16=bg_gattdb_adv_uuid16_map,
    .adv_uuid16_num=0,
    .adv_uuid128=bg_gattdb_adv_uuid128_map,
    .adv_uuid128_num=1,
};

const struct bg_gattdb_def *bg_gattdb=&bg_gattdb_data;
