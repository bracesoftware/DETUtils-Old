/*
 *
 * Code parse dependency
 *
 *
 *
 * DETUtils core
 *
 *
 */

new DET_g_RuntimeError[1024];

#define AnnounceDETUtilsError%0(%1) \
	format(DET_g_RuntimeError,sizeof DET_g_RuntimeError,%1);SaveDETUtilsLog(DET_g_RuntimeError)

#define DETUTILS_ERROR_1 "[DETUTils]: (error) - 1 :: Undefined command `%s`."
#define DETUTILS_ERROR_2 "[DETUTils]: (error) - 2 :: Undefined chatmode ID `%i`."
#define DETUTILS_ERROR_3 "[DETUTils]: (error) - 3 :: Undefined custom-prefixed command `%s`."