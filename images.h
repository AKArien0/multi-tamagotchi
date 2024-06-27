const unsigned char NO_IMAGE [] PROGMEM = {
};
// 'cursor', 16x16px
const unsigned char image_cursor [] PROGMEM = {
	0xff, 0xff, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01,
	0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0x80, 0x01, 0xff, 0xff
};
// 'icon_back', 16x16px
const unsigned char image_icon_back [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x0f, 0xe0, 0x1f, 0xf0, 0x0f, 0xf8, 0x04, 0x38,
	0x00, 0x18, 0x00, 0x18, 0x00, 0x38, 0x07, 0xf0, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'icon_check', 16x16px
const unsigned char image_icon_check [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xf8, 0x20, 0x04, 0x20, 0x04, 0x25, 0x44, 0x20, 0x04,
	0x20, 0x04, 0x18, 0xf8, 0x09, 0x00, 0x0a, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'icon_feed', 16x16px
const unsigned char image_icon_feed [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x01, 0x80, 0x0d, 0x30, 0x17, 0xf8, 0x38, 0xfc, 0x3f, 0xfc,
	0x3f, 0xfc, 0x3f, 0xfc, 0x1f, 0xf8, 0x1f, 0xf8, 0x0f, 0xf0, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x00
};
// 'icon_inject', 16x16px
const unsigned char image_icon_inject [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x12, 0x00, 0x24, 0x01, 0xc4, 0x02, 0xc8, 0x04, 0x44,
	0x0a, 0x80, 0x11, 0x00, 0x0a, 0x00, 0x34, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'icon_light_off', 16x16px
const unsigned char image_icon_light_off [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x04, 0x20, 0x0b, 0xd0, 0x16, 0x68, 0x15, 0xa8, 0x15, 0xa8,
	0x16, 0x68, 0x0b, 0x50, 0x04, 0xa0, 0x05, 0x20, 0x04, 0xa0, 0x02, 0x40, 0x01, 0x80, 0x00, 0x00
};
// 'icon_light_on', 16x16px
const unsigned char image_icon_light_on [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x20, 0x04, 0x13, 0xc8, 0x04, 0x20, 0x29, 0x94, 0x0a, 0x50, 0x2a, 0x54,
	0x09, 0x90, 0x27, 0x64, 0x02, 0xc0, 0x13, 0x48, 0x22, 0xc4, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00
};

const unsigned char* animation_icon_light[] PROGMEM = {
	image_icon_light_off,
	image_icon_light_on
};

// 'icon_rake', 16x16px
const unsigned char image_icon_rake [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x10, 0x00, 0x20, 0x00, 0x20, 0x00, 0x40, 0x00, 0x40,
	0x00, 0x80, 0x0c, 0x80, 0x0b, 0x00, 0x12, 0xc0, 0x04, 0xa0, 0x01, 0x20, 0x00, 0x40, 0x00, 0x00
};

// 'next_line_text_icon', 4x4px
const unsigned char image_next_line_text_icon [] PROGMEM = {
	0x10, 0x50, 0xf0, 0x40
};

// 'egg1', 48x48px
const unsigned char image_egg1 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00,
	0x0c, 0x30, 0x00, 0x00, 0x00, 0x00, 0x10, 0x08, 0x00, 0x00, 0x00, 0x00, 0x20, 0x04, 0x00, 0x00,
	0x00, 0x00, 0x40, 0x02, 0x00, 0x00, 0x00, 0x00, 0x8c, 0x01, 0x00, 0x00, 0x00, 0x00, 0x96, 0x01,
	0x00, 0x00, 0x00, 0x01, 0x12, 0x10, 0x80, 0x00, 0x00, 0x01, 0x1c, 0x10, 0x80, 0x00, 0x00, 0x02,
	0x00, 0x00, 0x40, 0x00, 0x00, 0x02, 0x00, 0x00, 0x40, 0x00, 0x00, 0x02, 0x00, 0x00, 0x40, 0x00,
	0x00, 0x04, 0x00, 0x10, 0x20, 0x00, 0x00, 0x04, 0x00, 0x00, 0x20, 0x00, 0x00, 0x04, 0x50, 0x18,
	0x20, 0x00, 0x00, 0x08, 0x00, 0x34, 0x10, 0x00, 0x00, 0x08, 0x90, 0x6c, 0x10, 0x00, 0x00, 0x08,
	0x00, 0x30, 0x10, 0x00, 0x00, 0x08, 0x40, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x08, 0x00,
	0x00, 0x10, 0x00, 0x0e, 0x08, 0x00, 0x00, 0x10, 0x0f, 0x02, 0x08, 0x00, 0x00, 0x10, 0x01, 0x80,
	0x08, 0x00, 0x00, 0x10, 0x00, 0x80, 0x08, 0x00, 0x00, 0x20, 0xc0, 0x00, 0x84, 0x00, 0x00, 0x20,
	0x00, 0x01, 0x84, 0x00, 0x00, 0x20, 0x00, 0x33, 0xc4, 0x00, 0x00, 0x20, 0x30, 0xe0, 0xc4, 0x00,
	0x00, 0x20, 0x22, 0x00, 0x04, 0x00, 0x00, 0x20, 0x26, 0x00, 0x04, 0x00, 0x00, 0x10, 0x1c, 0x00,
	0x08, 0x00, 0x00, 0x10, 0x00, 0x30, 0x08, 0x00, 0x00, 0x08, 0x00, 0x00, 0x10, 0x00, 0x00, 0x08,
	0x08, 0x00, 0x10, 0x00, 0x00, 0x04, 0x0c, 0x00, 0x20, 0x00, 0x00, 0x02, 0x00, 0x00, 0x40, 0x00,
	0x00, 0x01, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0xc0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x38, 0x1c,
	0x00, 0x00, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'egg2', 48x48px
const unsigned char image_egg2 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00,
	0x0c, 0x30, 0x00, 0x00, 0x00, 0x00, 0x10, 0x08, 0x00, 0x00, 0x00, 0x00, 0x20, 0x04, 0x00, 0x00,
	0x00, 0x00, 0x40, 0x02, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01,
	0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x80, 0x00, 0x00, 0x02,
	0xe0, 0x00, 0x40, 0x00, 0x00, 0x03, 0x9e, 0x00, 0x40, 0x00, 0x00, 0x02, 0x23, 0x00, 0x40, 0x00,
	0x00, 0x04, 0x81, 0x80, 0x20, 0x00, 0x00, 0x04, 0x90, 0x40, 0x20, 0x00, 0x00, 0x06, 0x04, 0x20,
	0x20, 0x00, 0x00, 0x08, 0x41, 0x30, 0x10, 0x00, 0x00, 0x0f, 0x08, 0x50, 0x10, 0x00, 0x00, 0x0c,
	0x41, 0x18, 0x10, 0x00, 0x00, 0x09, 0xa8, 0x68, 0x10, 0x00, 0x00, 0x10, 0x85, 0x0c, 0x08, 0x00,
	0x00, 0x16, 0x40, 0x84, 0xb8, 0x00, 0x00, 0x10, 0x56, 0x77, 0xc8, 0x00, 0x00, 0x15, 0x40, 0x0a,
	0xe8, 0x00, 0x00, 0x12, 0x24, 0xbf, 0x58, 0x00, 0x00, 0x20, 0x05, 0x5f, 0xec, 0x00, 0x00, 0x2d,
	0x41, 0x7b, 0xf4, 0x00, 0x00, 0x31, 0x2a, 0xeb, 0x74, 0x00, 0x00, 0x24, 0x21, 0xbf, 0xbc, 0x00,
	0x00, 0x20, 0x8f, 0xff, 0xfc, 0x00, 0x00, 0x2a, 0x23, 0xef, 0xfc, 0x00, 0x00, 0x12, 0x0f, 0x7d,
	0xf8, 0x00, 0x00, 0x13, 0x4e, 0xff, 0xf8, 0x00, 0x00, 0x09, 0xdf, 0xff, 0xf0, 0x00, 0x00, 0x0c,
	0x9b, 0xbf, 0xf0, 0x00, 0x00, 0x05, 0x7e, 0xff, 0xe0, 0x00, 0x00, 0x02, 0x2f, 0xff, 0xc0, 0x00,
	0x00, 0x01, 0xfb, 0xff, 0x80, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc,
	0x00, 0x00, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'egg3', 48x48px
const unsigned char image_egg3 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00,
	0x0c, 0x30, 0x00, 0x00, 0x00, 0x00, 0x10, 0x08, 0x00, 0x00, 0x00, 0x00, 0x23, 0x04, 0x00, 0x00,
	0x00, 0x00, 0x44, 0x02, 0x00, 0x00, 0x00, 0x00, 0x84, 0xe1, 0x00, 0x00, 0x00, 0x00, 0x99, 0xb1,
	0x00, 0x00, 0x00, 0x01, 0x21, 0x00, 0x80, 0x00, 0x00, 0x01, 0x22, 0x00, 0x80, 0x00, 0x00, 0x02,
	0x26, 0x00, 0x40, 0x00, 0x00, 0x02, 0x24, 0x00, 0x40, 0x00, 0x00, 0x02, 0x4c, 0x04, 0x40, 0x00,
	0x00, 0x04, 0x08, 0x06, 0x20, 0x00, 0x00, 0x04, 0x00, 0x02, 0x20, 0x00, 0x00, 0x04, 0x00, 0x01,
	0x20, 0x00, 0x00, 0x08, 0x00, 0x01, 0x10, 0x00, 0x00, 0x08, 0x00, 0x01, 0x10, 0x00, 0x00, 0x08,
	0x00, 0x01, 0x10, 0x00, 0x00, 0x08, 0x00, 0x00, 0x90, 0x00, 0x00, 0x10, 0x00, 0x00, 0x88, 0x00,
	0x00, 0x10, 0x00, 0x00, 0x88, 0x00, 0x00, 0x10, 0x00, 0x00, 0x88, 0x00, 0x00, 0x10, 0x00, 0x00,
	0x48, 0x00, 0x00, 0x10, 0x00, 0x00, 0x48, 0x00, 0x00, 0x20, 0x00, 0x00, 0x44, 0x00, 0x00, 0x20,
	0x00, 0x00, 0x44, 0x00, 0x00, 0x20, 0x00, 0x00, 0x84, 0x00, 0x00, 0x20, 0x00, 0x00, 0x84, 0x00,
	0x00, 0x20, 0x00, 0x00, 0x84, 0x00, 0x00, 0x20, 0x00, 0x00, 0x84, 0x00, 0x00, 0x10, 0x00, 0x00,
	0x88, 0x00, 0x00, 0x10, 0x00, 0x01, 0x08, 0x00, 0x00, 0x08, 0x00, 0x02, 0x10, 0x00, 0x00, 0x08,
	0x00, 0x04, 0x10, 0x00, 0x00, 0x04, 0x00, 0x18, 0x20, 0x00, 0x00, 0x02, 0x00, 0x20, 0x40, 0x00,
	0x00, 0x01, 0x01, 0xc0, 0x80, 0x00, 0x00, 0x00, 0xc0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x38, 0x1c,
	0x00, 0x00, 0x00, 0x00, 0x07, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'tama-1-1-alt', 48x48px
const unsigned char image_tama_1_1_alt [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00,
	0x00, 0x01, 0xc0, 0x03, 0x80, 0x00, 0x00, 0x03, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x1c, 0x00, 0x00,
	0x38, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x0f, 0x00, 0x01, 0x80, 0x00, 0x00, 0x01, 0x80, 0x03, 0x00,
	0x00, 0x00, 0x00, 0xc0, 0x06, 0x00, 0xc0, 0x03, 0x00, 0x60, 0x04, 0x01, 0x00, 0x00, 0x80, 0x20,
	0x04, 0x00, 0x00, 0x00, 0x00, 0x20, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x30, 0x18, 0x00, 0x00, 0x00,
	0x00, 0x18, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0c, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x07, 0x40, 0x00,
	0x00, 0x00, 0x00, 0x02, 0x78, 0x00, 0x03, 0xc0, 0x00, 0x1e, 0x08, 0x00, 0x0c, 0x30, 0x00, 0x10,
	0x18, 0x00, 0x06, 0x60, 0x00, 0x18, 0x10, 0x00, 0x01, 0x80, 0x00, 0x08, 0x10, 0x00, 0x00, 0x00,
	0x00, 0x08, 0x20, 0x00, 0x00, 0x00, 0x00, 0x04, 0x64, 0x00, 0x00, 0x00, 0x00, 0x26, 0x3e, 0x00,
	0x00, 0x00, 0x00, 0x7c, 0x02, 0x00, 0x01, 0x80, 0x00, 0x40, 0x02, 0x01, 0x02, 0x40, 0x80, 0x40,
	0x03, 0x0b, 0x3c, 0x3c, 0xd0, 0xc0, 0x01, 0xf6, 0xf0, 0x0f, 0x6f, 0x80, 0x00, 0x64, 0x00, 0x00,
	0x26, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'tama-1-1-anim-1', 48x48px
const unsigned char image_tama_1_1_anim_1 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0x00, 0x01, 0xc0, 0x03, 0x80, 0x00,
	0x00, 0x1e, 0x00, 0x00, 0x78, 0x00, 0x00, 0x78, 0x00, 0x00, 0x1e, 0x00, 0x00, 0xe0, 0x00, 0x00,
	0x07, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x01, 0x80, 0x00, 0x00, 0x01, 0x80, 0x03, 0x00,
	0x00, 0x00, 0x00, 0xc0, 0x06, 0x00, 0xc0, 0x03, 0x00, 0x60, 0x04, 0x00, 0x80, 0x01, 0x00, 0x20,
	0x1c, 0x00, 0x00, 0x00, 0x00, 0x38, 0x10, 0x00, 0x00, 0x00, 0x00, 0x08, 0x30, 0x00, 0x00, 0x00,
	0x00, 0x0c, 0x20, 0x00, 0x00, 0x00, 0x00, 0x04, 0x20, 0x00, 0x00, 0x00, 0x00, 0x04, 0x20, 0x00,
	0x00, 0x00, 0x00, 0x04, 0x38, 0x00, 0x0f, 0xf0, 0x00, 0x1c, 0x08, 0x00, 0x38, 0x1c, 0x00, 0x10,
	0x08, 0x00, 0x07, 0xe0, 0x00, 0x10, 0x04, 0x00, 0x00, 0x00, 0x00, 0x20, 0x04, 0x00, 0x00, 0x00,
	0x00, 0x20, 0x02, 0x00, 0x00, 0x00, 0x00, 0x40, 0x02, 0x00, 0x02, 0x40, 0x00, 0x40, 0x02, 0x00,
	0x4f, 0xf2, 0x00, 0x40, 0x02, 0x1d, 0xf0, 0x0f, 0xb8, 0x40, 0x02, 0x37, 0x80, 0x01, 0xec, 0x40,
	0x03, 0x73, 0x00, 0x00, 0xce, 0xc0, 0x01, 0xc0, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'tama-1-1-anim-2', 48x48px
const unsigned char image_tama_1_1_anim_2 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xf8, 0x00, 0x00, 0x00, 0x03,
	0xf0, 0x0f, 0xc0, 0x00, 0x00, 0x0f, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x38, 0x00, 0x00, 0x1c, 0x00,
	0x00, 0x70, 0x00, 0x00, 0x0e, 0x00, 0x01, 0xc0, 0x00, 0x00, 0x03, 0x80, 0x01, 0x80, 0x00, 0x00,
	0x01, 0x80, 0x02, 0x00, 0x00, 0x00, 0x00, 0x40, 0x06, 0x00, 0x00, 0x00, 0x00, 0x60, 0x04, 0x00,
	0x00, 0x00, 0x00, 0x20, 0x0c, 0x00, 0xc0, 0x03, 0x00, 0x30, 0x18, 0x00, 0x80, 0x01, 0x00, 0x18,
	0x10, 0x00, 0x00, 0x00, 0x00, 0x08, 0x10, 0x00, 0x00, 0x00, 0x00, 0x08, 0x30, 0x00, 0x00, 0x00,
	0x00, 0x0c, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x38, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x2c, 0x00,
	0x2c, 0x34, 0x00, 0x34, 0x3e, 0x00, 0x3f, 0xfc, 0x00, 0x7c, 0x06, 0x00, 0x01, 0x80, 0x00, 0x60,
	0x03, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x01, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x80, 0x00, 0x00,
	0x01, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x80, 0x02, 0x40, 0x01, 0x00, 0x00, 0xc0,
	0x4f, 0xf2, 0x03, 0x00, 0x01, 0x9d, 0xff, 0xff, 0xb9, 0x80, 0x01, 0x33, 0xc0, 0x03, 0xcc, 0x80,
	0x01, 0xff, 0x00, 0x00, 0xff, 0x80, 0x00, 0x60, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'tama-1-1-idle', 48x48px
const unsigned char image_tama_1_1_idle [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00,
	0x00, 0x01, 0xc0, 0x03, 0x80, 0x00, 0x00, 0x03, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x1c, 0x00, 0x00,
	0x38, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x0f, 0x00, 0x01, 0x80, 0x00, 0x00, 0x01, 0x80, 0x03, 0x00,
	0x00, 0x00, 0x00, 0xc0, 0x06, 0x00, 0xc0, 0x03, 0x00, 0x60, 0x04, 0x00, 0x80, 0x01, 0x00, 0x20,
	0x04, 0x00, 0x00, 0x00, 0x00, 0x20, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x30, 0x18, 0x00, 0x00, 0x00,
	0x00, 0x18, 0x30, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x20, 0x00, 0x00, 0x00, 0x00, 0x04, 0x20, 0x00,
	0x00, 0x00, 0x00, 0x04, 0x38, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x08, 0x00, 0x0d, 0xb0, 0x00, 0x10,
	0x18, 0x00, 0x07, 0xe0, 0x00, 0x18, 0x10, 0x00, 0x00, 0x00, 0x00, 0x08, 0x10, 0x00, 0x00, 0x00,
	0x00, 0x08, 0x10, 0x00, 0x00, 0x00, 0x00, 0x08, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x38, 0x06, 0x00,
	0x00, 0x00, 0x00, 0x60, 0x02, 0x00, 0x07, 0xe0, 0x00, 0x40, 0x02, 0x31, 0xcc, 0x33, 0x8c, 0x40,
	0x03, 0x2b, 0x78, 0x1e, 0xd4, 0xc0, 0x01, 0xc6, 0x00, 0x00, 0x63, 0x80, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'tama-2-1-alt', 48x48px
const unsigned char image_tama_2_1_alt [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x60, 0x06,
	0x00, 0x00, 0x00, 0x00, 0xc0, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x06,
	0x00, 0x00, 0x60, 0x00, 0x00, 0x04, 0x18, 0x18, 0x20, 0x00, 0x00, 0x08, 0x08, 0x10, 0x10, 0x00,
	0x00, 0x10, 0x00, 0x00, 0x08, 0x00, 0x00, 0x30, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x40, 0x00, 0x00,
	0x02, 0x00, 0x00, 0x40, 0x00, 0x00, 0x02, 0x00, 0x00, 0x40, 0x03, 0xc0, 0x02, 0x00, 0x00, 0xc0,
	0x00, 0x00, 0x03, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00,
	0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x03, 0xe0, 0x00, 0x00, 0x01, 0xc0, 0x02, 0x20, 0x00, 0x00,
	0x01, 0x40, 0x03, 0xc0, 0x00, 0x00, 0x01, 0xc0, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x80,
	0x00, 0x00, 0x03, 0x00, 0x00, 0x80, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x40, 0x00, 0x00, 0x3e, 0x00,
	0x00, 0x60, 0x00, 0x00, 0xde, 0x00, 0x00, 0x20, 0x00, 0x1b, 0x3c, 0x00, 0x00, 0x10, 0x03, 0x3c,
	0xc8, 0x00, 0x00, 0x18, 0x02, 0xd3, 0xd8, 0x00, 0x00, 0x06, 0x77, 0xfe, 0xe0, 0x00, 0x00, 0x03,
	0xeb, 0x7f, 0xc0, 0x00, 0x00, 0x00, 0xff, 0xf4, 0x80, 0x00, 0x00, 0x00, 0xd0, 0x05, 0x00, 0x00,
	0x00, 0x00, 0xd0, 0x05, 0x00, 0x00, 0x00, 0x00, 0x50, 0x05, 0x00, 0x00, 0x00, 0x00, 0x70, 0x06,
	0x00, 0x00, 0x00, 0x00, 0x60, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'tama-2-1-anim-1', 48x48px
const unsigned char image_tama_2_1_anim_1 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0x00, 0x00,
	0x00, 0x00, 0x60, 0x06, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00,
	0xc0, 0x00, 0x00, 0x06, 0x10, 0x08, 0x60, 0x00, 0x00, 0x04, 0x18, 0x18, 0x20, 0x00, 0x00, 0x08,
	0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x08, 0x00, 0x00, 0x30, 0x00, 0x00, 0x0c, 0x00,
	0x00, 0x40, 0x00, 0x00, 0x02, 0x00, 0x00, 0x40, 0x04, 0x20, 0x02, 0x00, 0x00, 0x40, 0x03, 0xc0,
	0x02, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x03, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x03, 0x80,
	0x00, 0x00, 0x01, 0x00, 0x04, 0xc0, 0x00, 0x00, 0x01, 0x00, 0x04, 0x40, 0x00, 0x00, 0x03, 0xe0,
	0x07, 0x80, 0x00, 0x00, 0x02, 0x60, 0x00, 0x80, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x80, 0x00, 0x00,
	0x01, 0x00, 0x00, 0x80, 0x00, 0x00, 0x07, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x40,
	0x00, 0x00, 0x1a, 0x00, 0x00, 0x60, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x30, 0x00, 0x02, 0x2c, 0x00,
	0x00, 0x10, 0x48, 0x9f, 0xe8, 0x00, 0x00, 0x18, 0xd6, 0x91, 0x98, 0x00, 0x00, 0x07, 0x09, 0xf8,
	0x60, 0x00, 0x00, 0x03, 0xfa, 0x07, 0xc0, 0x00, 0x00, 0x01, 0x2f, 0xff, 0x00, 0x00, 0x00, 0x00,
	0xa0, 0x0b, 0x00, 0x00, 0x00, 0x00, 0xb8, 0x09, 0x80, 0x00, 0x00, 0x00, 0x98, 0x0d, 0x80, 0x00,
	0x00, 0x00, 0x70, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'tama-2-1-anim-2', 48x48px
const unsigned char image_tama_2_1_anim_2 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x3f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x60, 0x06, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x03, 0x00, 0x00,
	0x00, 0x03, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x06, 0x10, 0x08, 0x60, 0x00, 0x00, 0x04, 0x08, 0x10,
	0x20, 0x00, 0x00, 0x08, 0x10, 0x08, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x08, 0x00, 0x00, 0x30,
	0x00, 0x00, 0x0c, 0x00, 0x00, 0x40, 0x00, 0x00, 0x02, 0x00, 0x00, 0x40, 0x04, 0x20, 0x02, 0x00,
	0x00, 0x40, 0x03, 0xc0, 0x02, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x03, 0x00, 0x06, 0x80, 0x00, 0x00,
	0x01, 0x30, 0x09, 0x80, 0x00, 0x00, 0x01, 0x48, 0x0c, 0x80, 0x00, 0x00, 0x01, 0x90, 0x06, 0x40,
	0x00, 0x00, 0x03, 0x90, 0x01, 0x80, 0x00, 0x00, 0x02, 0xe0, 0x00, 0x80, 0x00, 0x00, 0x01, 0x80,
	0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x80, 0x00, 0x00, 0x07, 0x00, 0x00, 0xc0, 0x00, 0x00,
	0x0f, 0x00, 0x00, 0x40, 0x00, 0x00, 0x1a, 0x00, 0x00, 0x60, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x30,
	0x00, 0x02, 0x2c, 0x00, 0x00, 0x10, 0x48, 0x9f, 0xe8, 0x00, 0x00, 0x18, 0xd6, 0x91, 0x98, 0x00,
	0x00, 0x07, 0x09, 0xf8, 0x60, 0x00, 0x00, 0x03, 0xfa, 0x07, 0xc0, 0x00, 0x00, 0x01, 0x2f, 0xff,
	0x00, 0x00, 0x00, 0x00, 0xa0, 0x0b, 0x00, 0x00, 0x00, 0x00, 0xb8, 0x09, 0x80, 0x00, 0x00, 0x00,
	0x98, 0x0d, 0x80, 0x00, 0x00, 0x00, 0x70, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'tama-2-1-anim-3', 48x48px
const unsigned char image_tama_2_1_anim_3 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0x00, 0x00,
	0x00, 0x00, 0x60, 0x06, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00,
	0xc0, 0x00, 0x00, 0x06, 0x18, 0x18, 0x60, 0x00, 0x00, 0x04, 0x08, 0x10, 0x20, 0x00, 0x00, 0x08,
	0x00, 0x00, 0x10, 0x00, 0x00, 0x10, 0x00, 0x00, 0x08, 0x00, 0x00, 0x30, 0x00, 0x00, 0x0c, 0x00,
	0x00, 0x40, 0x00, 0x00, 0x02, 0x00, 0x00, 0x40, 0x04, 0x20, 0x02, 0x00, 0x00, 0x40, 0x03, 0xc0,
	0x02, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x03, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x0c, 0x80,
	0x00, 0x00, 0x01, 0x00, 0x0e, 0x80, 0x00, 0x00, 0x01, 0xf8, 0x19, 0xc0, 0x00, 0x00, 0x03, 0x88,
	0x0c, 0x80, 0x00, 0x00, 0x02, 0xf0, 0x03, 0x80, 0x00, 0x00, 0x01, 0xc0, 0x00, 0x80, 0x00, 0x00,
	0x01, 0x00, 0x00, 0x80, 0x00, 0x00, 0x03, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x0b, 0x00, 0x00, 0x40,
	0x00, 0x00, 0x12, 0x00, 0x00, 0x60, 0x00, 0x00, 0xce, 0x00, 0x00, 0x30, 0x00, 0x02, 0x5c, 0x00,
	0x00, 0x10, 0x4a, 0xde, 0xa8, 0x00, 0x00, 0x18, 0xf6, 0x83, 0x58, 0x00, 0x00, 0x07, 0x29, 0xf8,
	0x60, 0x00, 0x00, 0x03, 0xfa, 0x07, 0xc0, 0x00, 0x00, 0x01, 0x2f, 0xfe, 0x00, 0x00, 0x00, 0x00,
	0xa0, 0x0a, 0x00, 0x00, 0x00, 0x00, 0xa0, 0x09, 0x00, 0x00, 0x00, 0x01, 0x20, 0x0a, 0x00, 0x00,
	0x00, 0x01, 0xc0, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'tama-2-1-idle', 48x48px
const unsigned char image_tama_2_1_idle [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x60, 0x06,
	0x00, 0x00, 0x00, 0x00, 0xc0, 0x03, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x06,
	0x00, 0x00, 0x60, 0x00, 0x00, 0x04, 0x18, 0x18, 0x20, 0x00, 0x00, 0x08, 0x08, 0x10, 0x10, 0x00,
	0x00, 0x10, 0x00, 0x00, 0x08, 0x00, 0x00, 0x30, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x40, 0x00, 0x00,
	0x02, 0x00, 0x00, 0x40, 0x00, 0x00, 0x02, 0x00, 0x00, 0x40, 0x03, 0xc0, 0x02, 0x00, 0x00, 0xc0,
	0x00, 0x00, 0x03, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00,
	0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x03, 0x80, 0x00, 0x00, 0x07, 0xc0, 0x02, 0x80, 0x00, 0x00,
	0x04, 0x40, 0x03, 0x80, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x80, 0x00, 0x00, 0x01, 0x00, 0x00, 0x80,
	0x00, 0x00, 0x05, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x40, 0x00, 0x00, 0x3a, 0x00,
	0x00, 0x60, 0x00, 0x01, 0xde, 0x00, 0x00, 0x30, 0x00, 0x0e, 0x3c, 0x00, 0x00, 0x10, 0x00, 0x38,
	0xe8, 0x00, 0x00, 0x18, 0xd6, 0xc7, 0x98, 0x00, 0x00, 0x07, 0x39, 0xf8, 0x60, 0x00, 0x00, 0x03,
	0xfe, 0x07, 0xc0, 0x00, 0x00, 0x01, 0x2f, 0xff, 0x00, 0x00, 0x00, 0x00, 0xa0, 0x0b, 0x00, 0x00,
	0x00, 0x00, 0xa0, 0x0b, 0x00, 0x00, 0x00, 0x00, 0xa0, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x60, 0x0e,
	0x00, 0x00, 0x00, 0x00, 0x60, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'tama-2-2-alt', 48x48px
const unsigned char image_tama_2_2_alt [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf8, 0x00, 0x00,
	0x00, 0x00, 0x18, 0x1e, 0x00, 0x00, 0x00, 0x00, 0x30, 0x03, 0x80, 0x00, 0x00, 0x00, 0x60, 0x00,
	0xc0, 0x00, 0x00, 0x00, 0x44, 0x00, 0x60, 0x00, 0x00, 0xf0, 0x80, 0x00, 0x30, 0x00, 0x00, 0x8f,
	0x00, 0x10, 0x10, 0x00, 0x00, 0x62, 0x00, 0x00, 0x10, 0x00, 0x00, 0x18, 0x00, 0x00, 0x10, 0x00,
	0x00, 0x0e, 0x00, 0x00, 0x20, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x20, 0x00, 0x01, 0x80, 0x00, 0x00,
	0x20, 0x00, 0x01, 0x3e, 0x00, 0x00, 0x20, 0x00, 0x01, 0xe1, 0x00, 0x00, 0x30, 0x00, 0x00, 0x01,
	0x00, 0x00, 0x10, 0x00, 0x00, 0x01, 0x00, 0x00, 0x10, 0x00, 0x00, 0x01, 0x00, 0x00, 0x10, 0x00,
	0x00, 0x01, 0x00, 0x00, 0x10, 0x00, 0x00, 0x01, 0x00, 0x00, 0x10, 0x00, 0x00, 0x01, 0x00, 0x00,
	0x10, 0x00, 0x00, 0x01, 0x00, 0x00, 0x30, 0x00, 0x00, 0x01, 0x00, 0x00, 0x20, 0x00, 0x00, 0x01,
	0x80, 0x00, 0x60, 0x00, 0x00, 0x00, 0x80, 0x00, 0x40, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x40, 0x00,
	0x00, 0x00, 0x60, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x30, 0x03, 0x80, 0x00, 0x00, 0x00, 0x18, 0x06,
	0x00, 0x00, 0x00, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'tama-2-2-anim-1', 48x48px
const unsigned char image_tama_2_2_anim_1 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x35, 0x00, 0x00, 0x00, 0x00, 0x00, 0x49, 0x01, 0xf8, 0x00,
	0x00, 0x00, 0x49, 0x83, 0x0c, 0x00, 0x00, 0x00, 0x4c, 0x8c, 0x06, 0x00, 0x00, 0x00, 0x44, 0xd8,
	0xc3, 0x00, 0x00, 0x00, 0x46, 0x70, 0x41, 0x00, 0x00, 0x00, 0x62, 0x20, 0x01, 0x80, 0x00, 0x00,
	0x23, 0x00, 0x00, 0x80, 0x00, 0x00, 0x11, 0x00, 0x0c, 0x80, 0x00, 0x00, 0x10, 0x00, 0x04, 0x80,
	0x00, 0x00, 0x30, 0x00, 0x00, 0x80, 0x00, 0x00, 0x20, 0x00, 0x00, 0x80, 0x00, 0x00, 0x40, 0x00,
	0x01, 0x80, 0x00, 0x00, 0x80, 0x00, 0x01, 0x00, 0x00, 0x00, 0x80, 0x00, 0x01, 0x00, 0x00, 0x00,
	0x80, 0x00, 0x01, 0x00, 0x00, 0x01, 0x80, 0x00, 0x03, 0x00, 0x00, 0x01, 0x00, 0x00, 0x02, 0x00,
	0x00, 0x02, 0x00, 0x00, 0x06, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00, 0x00, 0x02, 0x00, 0x00,
	0x0c, 0x00, 0x00, 0x02, 0x00, 0x00, 0x18, 0x00, 0x00, 0x02, 0x00, 0x00, 0x10, 0x00, 0x00, 0x02,
	0x00, 0x00, 0x20, 0x00, 0x00, 0x02, 0x00, 0x00, 0x40, 0x00, 0x00, 0x03, 0x00, 0x00, 0x40, 0x00,
	0x00, 0x01, 0x80, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x60, 0x00, 0x80, 0x00, 0x00, 0x00, 0x10, 0x01,
	0x00, 0x00, 0x00, 0x00, 0x0e, 0x02, 0x00, 0x00, 0x00, 0x00, 0x01, 0x8c, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'tama-2-2-anim-2', 48x48px
const unsigned char image_tama_2_2_anim_2 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xe0,
	0x00, 0x00, 0x00, 0x00, 0x60, 0x18, 0x00, 0x00, 0x00, 0x00, 0x80, 0x04, 0x00, 0x00, 0x00, 0x01,
	0x80, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x18, 0x31, 0x80, 0x00,
	0x00, 0x01, 0x10, 0x20, 0xc0, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x20, 0x00, 0x00, 0x80, 0x00, 0x00,
	0x20, 0x00, 0x00, 0xfe, 0x00, 0x00, 0x20, 0x00, 0x00, 0x80, 0x00, 0x00, 0x20, 0x00, 0x00, 0xc0,
	0x00, 0x00, 0x30, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x10, 0x00, 0x00, 0x01, 0x00, 0x00, 0x18, 0x00,
	0x00, 0x01, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x01, 0x00, 0x00, 0x04, 0x00, 0x00, 0x03, 0x00, 0x00,
	0x04, 0x00, 0x00, 0x02, 0x00, 0x00, 0x04, 0x00, 0x00, 0x06, 0x00, 0x00, 0x04, 0x00, 0x00, 0x04,
	0x00, 0x00, 0x04, 0x00, 0x00, 0x06, 0x00, 0x00, 0x04, 0x00, 0x00, 0x03, 0x00, 0x00, 0x18, 0x00,
	0x00, 0x01, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x01, 0xf0, 0x03, 0x80, 0x00, 0x00, 0x00, 0x38, 0x06,
	0x00, 0x00, 0x00, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'tama-2-2-anim-3', 48x48px
const unsigned char image_tama_2_2_anim_3 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x0f,
	0x07, 0x00, 0x00, 0x00, 0x00, 0x18, 0x01, 0xc0, 0x00, 0x00, 0x00, 0x30, 0x18, 0x60, 0x00, 0x00,
	0x00, 0x20, 0x10, 0x30, 0x00, 0x00, 0x00, 0x26, 0x00, 0x10, 0x00, 0x00, 0x00, 0x24, 0x00, 0x08,
	0x00, 0x00, 0x00, 0x20, 0x00, 0x04, 0x00, 0x00, 0x01, 0xf0, 0x00, 0x06, 0x00, 0x00, 0x03, 0x00,
	0x00, 0x02, 0x00, 0x00, 0x04, 0x70, 0x00, 0x03, 0x00, 0x00, 0x05, 0xc0, 0x00, 0x01, 0x80, 0x00,
	0x03, 0x00, 0x00, 0x00, 0x80, 0x00, 0x02, 0x18, 0x00, 0x00, 0xc0, 0x00, 0x06, 0x7c, 0x00, 0x00,
	0x60, 0x00, 0x07, 0xc4, 0x00, 0x00, 0x60, 0x00, 0x00, 0x04, 0x00, 0x00, 0x20, 0x00, 0x00, 0x02,
	0x00, 0x00, 0x30, 0x00, 0x00, 0x02, 0x00, 0x00, 0x10, 0x00, 0x00, 0x03, 0x00, 0x00, 0x10, 0x00,
	0x00, 0x01, 0x00, 0x00, 0x18, 0x00, 0x00, 0x01, 0x00, 0x00, 0x08, 0x00, 0x00, 0x01, 0x80, 0x00,
	0x08, 0x00, 0x00, 0x00, 0x80, 0x00, 0x08, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x08, 0x00, 0x00, 0x00,
	0x40, 0x00, 0x18, 0x00, 0x00, 0x00, 0x60, 0x00, 0x10, 0x00, 0x00, 0x00, 0x30, 0x00, 0x30, 0x00,
	0x00, 0x00, 0x10, 0x00, 0x60, 0x00, 0x00, 0x00, 0x18, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x0c, 0x03,
	0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x01, 0x98, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'tama-2-2-idle', 48x48px
const unsigned char image_tama_2_2_idle [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xe0, 0x00, 0x00,
	0x00, 0x00, 0x60, 0x18, 0x00, 0x00, 0x00, 0x00, 0x80, 0x04, 0x00, 0x00, 0x00, 0x01, 0x80, 0x02,
	0x00, 0x00, 0x00, 0x01, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x10, 0x11, 0x80, 0x00, 0x00, 0x01,
	0x00, 0x00, 0xc0, 0x00, 0x00, 0x7e, 0x00, 0x00, 0x20, 0x00, 0x00, 0x80, 0x00, 0x00, 0x20, 0x00,
	0x00, 0xfe, 0x00, 0x00, 0x20, 0x00, 0x00, 0x80, 0x00, 0x00, 0x20, 0x00, 0x00, 0xc0, 0x00, 0x00,
	0x30, 0x00, 0x00, 0x3e, 0x00, 0x00, 0x10, 0x00, 0x00, 0x01, 0x00, 0x00, 0x10, 0x00, 0x00, 0x01,
	0x00, 0x00, 0x10, 0x00, 0x00, 0x01, 0x00, 0x00, 0x10, 0x00, 0x00, 0x01, 0x00, 0x00, 0x10, 0x00,
	0x00, 0x01, 0x00, 0x00, 0x10, 0x00, 0x00, 0x01, 0x00, 0x00, 0x10, 0x00, 0x00, 0x01, 0x00, 0x00,
	0x10, 0x00, 0x00, 0x01, 0x00, 0x00, 0x30, 0x00, 0x00, 0x01, 0x00, 0x00, 0x20, 0x00, 0x00, 0x01,
	0x80, 0x00, 0x60, 0x00, 0x00, 0x00, 0x80, 0x00, 0x40, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x40, 0x00,
	0x00, 0x00, 0x60, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x30, 0x03, 0x80, 0x00, 0x00, 0x00, 0x18, 0x06,
	0x00, 0x00, 0x00, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char* egg_animation [] PROGMEM = {
	image_egg1,
	image_egg2
};

const unsigned char* animation_tama_1_1_idle [] PROGMEM = {
	image_tama_1_1_idle,
	image_tama_1_1_alt
};

const unsigned char* animation_tama_1_1_event [] PROGMEM = {
	image_tama_1_1_anim_1,
	image_tama_1_1_anim_2,
	image_tama_1_1_alt
};

const unsigned char* animation_tama_2_1_idle [] PROGMEM = {
	image_tama_2_1_idle,
	image_tama_2_1_alt
};

const unsigned char* animation_tama_2_1_event [] PROGMEM = {
	image_tama_2_1_anim_1,
	image_tama_2_1_anim_2,
	image_tama_2_1_anim_3,
	image_tama_2_1_anim_1
};

const unsigned char* animation_tama_2_2_idle [] PROGMEM = {
	image_tama_2_2_idle,
	image_tama_2_2_alt
};

const unsigned char* animation_tama_2_2_event [] PROGMEM = {
	image_tama_2_1_anim_1,
	image_tama_2_1_anim_2,
	image_tama_2_1_anim_3,
	image_tama_2_1_anim_2
};

// 'little-cursor', 12x12px
const unsigned char image_little_cursor [] PROGMEM = {
	0xff, 0xf0, 0x80, 0x10, 0x80, 0x10, 0x80, 0x10, 0x80, 0x10, 0x80, 0x10, 0x80, 0x10, 0x80, 0x10,
	0x80, 0x10, 0x80, 0x10, 0x80, 0x10, 0xff, 0xf0
};

// 'tama-0-1-mini-1', 12x12px
const unsigned char image_tama_0_1_mini_1 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x09, 0x00, 0x10, 0x80, 0x12, 0x80, 0x20, 0x40, 0x28, 0x40,
	0x21, 0x40, 0x10, 0x80, 0x0f, 0x00, 0x00, 0x00
};

// 'tama-1-1-mini-1', 12x12px
const unsigned char image_tama_1_1_mini_1 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x30, 0xc0, 0x29, 0x40, 0x40, 0x20, 0x26, 0x40,
	0x10, 0x80, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'tama-1-1-mini-2', 12x12px
const unsigned char image_tama_1_1_mini_2 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x30, 0xc0, 0x69, 0x60, 0x40, 0x20, 0x26, 0x40, 0x10, 0x80,
	0x10, 0x80, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'tama-2-1-mini-1', 12x12px
const unsigned char image_tama_2_1_mini_1 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x10, 0x80, 0x25, 0x40, 0x20, 0x40, 0x36, 0xc0, 0x10, 0x80,
	0x1f, 0x80, 0x0b, 0x00, 0x09, 0x00, 0x00, 0x00
};
// 'tama-2-1-mini-2', 12x12px
const unsigned char image_tama_2_1_mini_2 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x10, 0x80, 0x2a, 0x40, 0x20, 0x40, 0x36, 0xc0, 0x10, 0x80,
	0x1f, 0x80, 0x0d, 0x00, 0x09, 0x00, 0x00, 0x00
};
// 'tama-2-2-mini-1', 12x12px
const unsigned char image_tama_2_2_mini_1 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x09, 0x00, 0x32, 0x80, 0x20, 0x80, 0x18, 0x80, 0x08, 0x80,
	0x08, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'tama-2-2-mini-2', 12x12px
const unsigned char image_tama_2_2_mini_2 [] PROGMEM = {
	0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x19, 0x00, 0x2a, 0x80, 0x30, 0x80, 0x08, 0x80, 0x08, 0x80,
	0x08, 0x80, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00
};

const unsigned char* animation_tama_1_1_mini [] PROGMEM = {
	image_tama_1_1_mini_1,
	image_tama_1_1_mini_2
};

const unsigned char* animation_tama_2_1_mini [] PROGMEM = {
	image_tama_2_1_mini_1,
	image_tama_2_1_mini_2
};

const unsigned char* animation_tama_2_2_mini [] PROGMEM = {
	image_tama_2_2_mini_1,
	image_tama_2_2_mini_2
};

const unsigned char* animation_tama_0_1_mini [] PROGMEM = {
	image_tama_0_1_mini_1,
	image_tama_0_1_mini_1
};
