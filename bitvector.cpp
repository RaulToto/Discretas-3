
class BitVector
{
private:
    int m_len;
    bool* m_vec;

public:
    // c'tors / d'tor
    BitVector();
    BitVector(int len);
    BitVector(const BitVector&);
    void SetBit(int,bool);
    ~BitVector();

    // public interface
    BitVector Extended();

    // getter
    int Length () const { return m_len; }

    // public operators
    BitVector& operator= (const BitVector&);
    bool& operator[] (int);
    const bool& operator[](int) const;

    // output
    friend ostream& operator<< (ostream&, const BitVector&);
};

BitVector::BitVector()
{
    m_len = 0;
    m_vec = (bool*) 0;
}

BitVector::BitVector(int len)
{
    m_len = len;
    m_vec = new bool [m_len];

    for (int i = 0; i < m_len; i ++)
        m_vec[i] = false;
}

BitVector::BitVector(const BitVector& v)
{
    m_len = v.m_len;
    m_vec = new bool [m_len];

    for (int i = 0; i < m_len; i ++)
        m_vec[i] = v.m_vec[i];
}
void BitVector::SetBit(int pos, bool def)
{
    int part=pos/8;
    int pos_part=pos%8;
    unsigned char adolfo=1<<pos_part;

    if(def)
    {
        vector[part]=vector[part]|adolfo;
    }
    else
    {
        int tmp= ~adolfo;
        vector[part]=vector[part]&tmp;
    }

}
BitVector::~BitVector()
{
    delete[] m_vec;
}

BitVector BitVector::Extended()
{
    BitVector v (m_len + 1);

    for (int i = 0; i < m_len; i++)
        v.m_vec[i + 1] = m_vec[i];

    // clear most significant bit
    v.m_vec[0] = false;

    return v;
}

bool& BitVector::operator[] (int i)
{
    return m_vec [i];
}

const bool& BitVector::operator[](int i) const
{
    return m_vec [i];
}

BitVector& BitVector::operator= (const BitVector& v)
{
    if (this == &v)
        return *this;

    delete[] m_vec;

    m_len = v.m_len;
    m_vec = new bool [m_len];

    for (int i = 0; i < m_len; i ++)
        m_vec[i] = v.m_vec[i];

    return *this;
}

ostream& operator<< (ostream& os, const BitVector& v)
{
    for (int i = 0; i < v.m_len; i ++)
        os << (v[i] == true) ? '1' : '0';

    return os;
}