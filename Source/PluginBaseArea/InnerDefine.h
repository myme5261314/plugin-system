#ifndef _INNNER_DEFINE_H_
#define _INNNER_DEFINE_H_


//////////////////////////内部定义文件///////////////////////////////////////

class CPluginDllManager;
class CDataPluginManager;
class CFunctionPluginManager;
class CMessageListenerManager;
class CDataElementManager;

//##ModelId=4C5D1B0901AB
struct WorkspaceInfoStrcT
{
	//##ModelId=4C5D1B0901BC
	CPluginDllManager		*m_pDllManager;
	//##ModelId=4C5D1B0901C1
	CFunctionPluginManager	*m_pFunctionManager;
	//##ModelId=4DE7365902D7
	CDataPluginManager		*m_pDataManager;
	//##ModelId=4C5D1B0901CB
	CMessageListenerManager	*m_pMsgListenerManager;
	//##ModelId=4C5F6FC2025A
	CDataElementManager     *m_pElementManager;

	//##ModelId=4C5D1B0901CF
	WorkspaceInfoStrcT()
	{
		m_pDllManager         = NULL;
		m_pFunctionManager    = NULL;
		m_pMsgListenerManager = NULL;
		m_pElementManager     = NULL;
	}
};

////////////////////////////////////////////////////////////////////////////////////

//##ModelId=4C5FE0CC0331
template <class T>
    class MapIterator
    {
    private:
	//##ModelId=4C5FE0CC0361
        typename T::iterator mCurrent;
	//##ModelId=4C5FE0CC0366
        typename T::iterator mEnd;
        /// Private constructor since only the parameterised constructor should be used
	//##ModelId=4C5FE0CC036A
        MapIterator() {};
    public:
        typedef typename T::referent_type MappedType;
        typedef typename T::key_type KeyType;

        /** Constructor.
        @remarks
            Provide a start and end iterator to initialise.
        */
	//##ModelId=4DE736C4024D
        MapIterator(typename T::iterator start, typename T::iterator end)
            : mCurrent(start), mEnd(end)
        {
        }

        /** Constructor.
        @remarks
            Provide a container to initialise.
        */
	//##ModelId=4C5FE0CC036B
        explicit MapIterator(typename T& c)
            : mCurrent(c.begin()), mEnd(c.end())
        {
        }

        /** Returns true if there are more items in the collection. */
	//##ModelId=4C5FE0CC0370
        bool hasMoreElements(void) const
        {
            return mCurrent != mEnd;
        }

        /** Returns the next value element in the collection, and advances to the next. */
	//##ModelId=4C5FE0CC0373
        typename T::referent_type getNext(void)
        {
            return (mCurrent++)->second;
        }
        /** Returns the next value element in the collection, without advancing to the next. */
	//##ModelId=4C5FE0CC0375
        typename T::referent_type peekNextValue(void)
        {
            return mCurrent->second;
        }
        /** Returns the next key element in the collection, without advancing to the next. */
	//##ModelId=4C5FE0CC0377
        typename T::key_type peekNextKey(void)
        {
            return mCurrent->first;
        }
        /** Required to overcome intermittent bug */
	//##ModelId=4C5FE0CC037F
 	    MapIterator<T> & operator=( MapIterator<T> &rhs )
 	    {
 		    mCurrent = rhs.mCurrent;
 		    mEnd = rhs.mEnd;
 		    return *this;
 	    }
        /** Returns a pointer to the next value element in the collection, without 
            advancing to the next afterwards. */
	//##ModelId=4C5FE0CC0381
        typename T::referent_type* peekNextValuePtr(void)
        {
            return &(mCurrent->second);
        }
        /** Moves the iterator on one element. */
	//##ModelId=4C5FE0CC0383
        void moveNext(void)
        {
            ++mCurrent;
        }
    };



////////////////////////////////////////////////////////////////////////////
template <class T>
class VectorIterator
{
	private:
		typename typename T::iterator mCurrent;
		typename typename T::iterator mEnd;

		VectorIterator() {};
	public:
		typedef typename T::value_type ValueType;


		VectorIterator(typename T::iterator start, typename T::iterator end)
			: mCurrent(start), mEnd(end)
		{
		}

		bool hasMoreElements(void) const
		{
			return mCurrent != mEnd;
		}

		typename T::value_type getNext(void)
		{
			return *mCurrent++;
		}

		typename T::value_type peekNext(void)
		{
			return *mCurrent;
		}

		typename T::pointer peekNextPtr(void)
		{
			return &(*mCurrent);
		}

		void moveNext(void)
		{
			mCurrent++;
		}
};


////////////////////////////////////////////////////////////////////////////

//获取当前程序路径.
bool GetCurrentModulePath(char *pFilePath);

//判断文件是否存在, 并判断文件是否为空.
bool IsFileExisted(const char *pFilePathName, bool IsEmptyJudge=true);

//搜索并形成插件列表文件.
bool FormPluginLstFile(const char *pFilePath);







#endif
