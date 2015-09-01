//
//  LVHeads.h
//  JU
//
//  Created by dongxicheng on 12/29/14.
//  Copyright (c) 2014 ju.taobao.com. All rights reserved.
//

#ifndef JU_LVHeads_h
#define JU_LVHeads_h
//--------------------------------------------------------------------------------

#import "lV.h"
#import "lVauxlib.h"
#import "lVlib.h"
#import "lVstate.h"
#import "lVgc.h"
#import "LVUtil.h"
//--------------------------------------------------------------------------------

#define USERDATA_KEY_DELEGATE 1
#define USERDATA_FLEX_DELEGATE 2

//---------------用户数据包含的公用头信息---------------------------------------------
#define LVUserDataCommonHead  int type; const char* typeName

//---------------创建用户数据-------------------------------------------------------
#define NEW_USERDATA(var, T)    \
    T* var = ( (T*)lv_newuserdata( L, sizeof(T)) ); \
    lv_createUDataLuatable(L,-1);\
    var->type = LVID_##T; \
    var->typeName = #T ;

//----------------用户数据的类型检查-------------------------------------------------
#define LVIsType(user,T)  (user && user->type==LVID_##T)

//----------------用户数据类型 ID---------------------------------------------------
typedef enum : NSUInteger {
    LVID_LVUserDataView,
    LVID_LVUserDataData,
    LVID_LVUserDataDate,
    LVID_LVUserDataHttp,
    LVID_LVUserDataMtop,
    LVID_LVUserDataTimer,
    LVID_LVUserDataTransform3D,
    LVID_LVUserDataGesture,
    LVID_LVUserDataDownloader,
    LVID_LVUserDataAudioPlayer,
    LVID_LVUserDataAttributedString,
    LVID_LVUserDataNativeObject,
    LVID_LVUserDataStruct,
} LVUserDataIDS;

//----------------View的用户数据结构------------------------------------------------
typedef struct _LVUserDataView {
    LVUserDataCommonHead;
    const void* view;
} LVUserDataView;

//----------------手势的用户数据结构-------------------------------------------------
typedef struct _LVUserDataGesture {
    LVUserDataCommonHead;
    const void* gesture;
} LVUserDataGesture;

//--------------------------------------------------------------------------------
@class LView;
@protocol LVProtocal <NSObject>
@required
@property(nonatomic,weak) LView* lv_lview;
@property(nonatomic,assign) LVUserDataView* lv_userData;
@end


//-----------------------metatable------------------------------------------------
#define META_TABLE_UIButton         "UI.Button"
#define META_TABLE_UIScrollView     "UI.ScrollView"
#define META_TABLE_UIView           "UI.View"
#define META_TABLE_UIViewNewIndex   "UI.View.NewIndex"
#define META_TABLE_Timer            "LV.Timer"
#define META_TABLE_Http             "LV.Http"
#define META_TABLE_Mtop             "LV.Mtop"
#define META_TABLE_Gesture          "LV.GestureRecognizer"
#define META_TABLE_PanGesture       "LV.Pan.GestureRecognizer"
#define META_TABLE_TapGesture       "LV.Tap.GestureRecognizer"
#define META_TABLE_PinchGesture     "LV.Pinch.GestureRecognizer"
#define META_TABLE_RotaionGesture   "LV.Rotaion.GestureRecognizer"
#define META_TABLE_SwipeGesture     "LV.Swipe.GestureRecognizer"
#define META_TABLE_LongPressGesture "LV.LongPress.GestureRecognizer"
#define META_TABLE_Date             "LV.Date"
#define META_TABLE_Data             "LV.Data"
#define META_TABLE_UIPageControl    "UI.PageControl"
#define META_TABLE_UIActivityIndicatorView    "UI.UIActivityIndicator"
#define META_TABLE_LoadingView      "UI.LoadingView"
#define META_TABLE_ErrorView        "UI.ErrorView"
#define META_TABLE_NoticeView       "UI.NoticeView"
#define META_TABLE_UIImageView      "UI.ImageView"
#define META_TABLE_UILabel          "UI.Label"
#define META_TABLE_UITextField      "UI.TextField"
#define META_TABLE_UITableView      "UI.TableView"
#define META_TABLE_UITableViewCell  "UI.TableView.Cell"
#define META_TABLE_UICollectionView      "UI.CollectionView"
#define META_TABLE_UICollectionViewCell  "UI.CollectionView.Cell"
#define META_TABLE_UIAlertView      "UI.AlertView"
#define META_TABLE_Transform3D      "UI.Transfrom3D"
#define META_TABLE_Struct           "UI.Struct"
#define META_TABLE_Downloader       "lv.Downloader"
#define META_TABLE_AudioPlayer      "lv.AudioPlayer"
#define META_TABLE_AttributedString "lv.AttributedString"
#define META_TABLE_Global           "lv.global"
#define META_TABLE_NativeObject     "lv.nativeObjBox"

// lua对象 -> NSString
NSString* lv_paramString(lv_State* L, int idx );

// run
int  lv_runFunction(lv_State* l);
int  lv_runFunctionWithArgs(lv_State* l, int nargs, int nret);
void lv_stopAndExitNow(lv_State* l);



//--------------------------------------------------------------------------------
@interface LVHeads : NSObject
@end


#define HEADER_BEGIN_REFRESHING  @"HeaderBeginRefreshing"
#define FOOTER_BEGIN_REFRESHING  @"FooterBeginRefreshing"


typedef enum:int{
    LVTypeID_NONE = 0,
    LVTypeID_void,
    LVTypeID_BOOL,
    LVTypeID_bool,
    LVTypeID_char,
    LVTypeID_unsignedchar,
    LVTypeID_short,
    LVTypeID_unsignedshort,
    LVTypeID_int,
    LVTypeID_unsignedint,
    LVTypeID_NSInteger,
    LVTypeID_NSUInteger,
    LVTypeID_longlong,
    LVTypeID_unsigedlonglong,
    LVTypeID_float,
    LVTypeID_CGFloat,
    LVTypeID_double,
    LVTypeID_charP,
    LVTypeID_voidP,
    LVTypeID_id,
    LVTypeID_idP,
    LVTypeID_struct,
}LVTypeIDEnum;


LVTypeIDEnum lv_typeID(const char* type);

#define isNormalRect(r)  ( !( isnan(r.origin.x) || isnan(r.origin.y) || isnan(r.size.width) || isnan(r.size.height) ) )
#define isNormalSize(s)  ( !( isnan(s.width) || isnan(s.height) ) )
#define isNormalPoint(p)  ( !( isnan(p.x) || isnan(p.y) ) )
#define isNormalEdgeInsets(e)  ( !( isnan(e.top) || isnan(e.left) || isnan(e.bottom) || isnan(e.right) ) )


typedef void(^LVLoadFinished)(void);

#endif
