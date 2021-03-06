// Code auto-generated by piet-gpu-derive

struct TileHeaderRef {
    uint offset;
};

struct ItemHeaderRef {
    uint offset;
};

struct SegmentRef {
    uint offset;
};

struct TileHeader {
    uint n;
    ItemHeaderRef items;
};

#define TileHeader_size 8

TileHeaderRef TileHeader_index(TileHeaderRef ref, uint index) {
    return TileHeaderRef(ref.offset + index * TileHeader_size);
}

struct ItemHeader {
    uint n;
    SegmentRef segments;
};

#define ItemHeader_size 8

ItemHeaderRef ItemHeader_index(ItemHeaderRef ref, uint index) {
    return ItemHeaderRef(ref.offset + index * ItemHeader_size);
}

struct Segment {
    vec2 start;
    vec2 end;
};

#define Segment_size 16

SegmentRef Segment_index(SegmentRef ref, uint index) {
    return SegmentRef(ref.offset + index * Segment_size);
}

TileHeader TileHeader_read(TileHeaderRef ref) {
    uint ix = ref.offset >> 2;
    uint raw0 = segment[ix + 0];
    uint raw1 = segment[ix + 1];
    TileHeader s;
    s.n = raw0;
    s.items = ItemHeaderRef(raw1);
    return s;
}

void TileHeader_write(TileHeaderRef ref, TileHeader s) {
    uint ix = ref.offset >> 2;
    segment[ix + 0] = s.n;
    segment[ix + 1] = s.items.offset;
}

ItemHeader ItemHeader_read(ItemHeaderRef ref) {
    uint ix = ref.offset >> 2;
    uint raw0 = segment[ix + 0];
    uint raw1 = segment[ix + 1];
    ItemHeader s;
    s.n = raw0;
    s.segments = SegmentRef(raw1);
    return s;
}

void ItemHeader_write(ItemHeaderRef ref, ItemHeader s) {
    uint ix = ref.offset >> 2;
    segment[ix + 0] = s.n;
    segment[ix + 1] = s.segments.offset;
}

Segment Segment_read(SegmentRef ref) {
    uint ix = ref.offset >> 2;
    uint raw0 = segment[ix + 0];
    uint raw1 = segment[ix + 1];
    uint raw2 = segment[ix + 2];
    uint raw3 = segment[ix + 3];
    Segment s;
    s.start = vec2(uintBitsToFloat(raw0), uintBitsToFloat(raw1));
    s.end = vec2(uintBitsToFloat(raw2), uintBitsToFloat(raw3));
    return s;
}

void Segment_write(SegmentRef ref, Segment s) {
    uint ix = ref.offset >> 2;
    segment[ix + 0] = floatBitsToUint(s.start.x);
    segment[ix + 1] = floatBitsToUint(s.start.y);
    segment[ix + 2] = floatBitsToUint(s.end.x);
    segment[ix + 3] = floatBitsToUint(s.end.y);
}

