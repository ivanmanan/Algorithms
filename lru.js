class LRU {

  constructor(capacity) {
    this.m_size = capacity;
    this.cache = {};
    this.list = [];
  }

  read(key) {

    let value = this.cache[key];

    console.log(value);
  }

  write(key, value) {
    cache[key] = value;
  }
}

LRU.write(1,2);
LRU.read(1);