<?php

/*
 * Note: test names match method names in a set of PHPUnit tests
 * in a userland package.  Please be so kind as to leave them.
 */

date_default_timezone_set('America/New_York');


/*
 * Time, Fall, Zone Type 3 to Zone Type 3
 *
 * + prev: the day before the transition day  2010-11-06 18:38:28
 * + dt: daylight time on transition day      2010-11-07 00:10:20
 * + redodt: daylight time in the redo period 2010-11-07 01:12:33 EDT, + TZ
 * + redost: standard time in the redo period 2010-11-07 01:14:44 EST, + TZ
 * + st: standard time on the transition day  2010-11-07 03:16:55
 * + post: the day after the transition day   2010-11-08 19:59:59
 */
echo "test_time_fall_type3_prev_type3_prev: ";
$end   = new DateTime('2010-11-06 18:38:28');  // prev, zt3
$start = new DateTime('2010-10-04 02:18:48');  // sp prev, zt3
examine_diff($end, $start, 'P+0Y1M2DT16H19M40S', 33);

echo "test_time_fall_type3_prev_type3_dt: ";
$end   = new DateTime('2010-11-07 00:10:20');  // dt, zt3
$start = new DateTime('2010-11-06 18:38:28');  // prev, zt3
examine_diff($end, $start, 'P+0Y0M0DT5H31M52S', 0);

echo "test_time_fall_type3_prev_type3_redodt: ";
$end   = new DateTime('2010-11-07 01:12:33 EDT');  // redodt, zt2
$end->setTimezone(new DateTimeZone('America/New_York'));  // zt2 -> zt3
$start = new DateTime('2010-11-06 18:38:28');  // prev, zt3
examine_diff($end, $start, 'P+0Y0M0DT6H34M5S', 0);

echo "test_time_fall_type3_prev_type3_redost: ";
$end   = new DateTime('2010-11-07 01:14:44 EST');  // redost, zt2
$end->setTimezone(new DateTimeZone('America/New_York'));  // zt2 -> zt3
$start = new DateTime('2010-11-06 18:38:28');  // prev, zt3
examine_diff($end, $start, 'P+0Y0M0DT7H36M16S', 0);

echo "test_time_fall_type3_prev_type3_st: ";
$end   = new DateTime('2010-11-07 03:16:55');  // st, zt3
$start = new DateTime('2010-11-06 18:38:28');  // prev, zt3
examine_diff($end, $start, 'P+0Y0M0DT9H38M27S', 0);

echo "test_time_fall_type3_prev_type3_post: ";
$end   = new DateTime('2010-11-08 19:59:59');  // post, zt3
$start = new DateTime('2010-11-06 18:38:28');  // prev, zt3
examine_diff($end, $start, 'P+0Y0M2DT1H21M31S', 2);

echo "test_time_fall_type3_dt_type3_prev: ";
$end   = new DateTime('2010-11-06 18:38:28');  // prev, zt3
$start = new DateTime('2010-11-07 00:10:20');  // dt, zt3
examine_diff($end, $start, 'P-0Y0M0DT5H31M52S', 0);

echo "test_time_fall_type3_dt_type3_dt: ";
$end   = new DateTime('2010-11-07 00:15:35');  // sp dt, zt3
$start = new DateTime('2010-11-07 00:10:20');  // dt, zt3
examine_diff($end, $start, 'P+0Y0M0DT0H5M15S', 0);

echo "test_time_fall_type3_dt_type3_redodt: ";
$end   = new DateTime('2010-11-07 01:12:33 EDT');  // redodt, zt2
$end->setTimezone(new DateTimeZone('America/New_York'));  // zt2 -> zt3
$start = new DateTime('2010-11-07 00:10:20');  // dt, zt3
examine_diff($end, $start, 'P+0Y0M0DT1H2M13S', 0);

echo "test_time_fall_type3_dt_type3_redost: ";
$end   = new DateTime('2010-11-07 01:14:44 EST');  // redost, zt2
$end->setTimezone(new DateTimeZone('America/New_York'));  // zt2 -> zt3
$start = new DateTime('2010-11-07 00:10:20');  // dt, zt3
examine_diff($end, $start, 'P+0Y0M0DT2H4M24S', 0);

echo "test_time_fall_type3_dt_type3_st: ";
$end   = new DateTime('2010-11-07 03:16:55');  // st, zt3
$start = new DateTime('2010-11-07 00:10:20');  // dt, zt3
examine_diff($end, $start, 'P+0Y0M0DT4H6M35S', 0);

echo "test_time_fall_type3_dt_type3_post: ";
$end   = new DateTime('2010-11-08 19:59:59');  // post, zt3
$start = new DateTime('2010-11-07 00:10:20');  // dt, zt3
examine_diff($end, $start, 'P+0Y0M1DT20H49M39S', 1);

echo "test_time_fall_type3_redodt_type3_prev: ";
$end   = new DateTime('2010-11-06 18:38:28');  // prev, zt3
$start = new DateTime('2010-11-07 01:12:33 EDT');  // redodt, zt2
$start->setTimezone(new DateTimeZone('America/New_York'));  // zt2 -> zt3
examine_diff($end, $start, 'P-0Y0M0DT6H34M5S', 0);

echo "test_time_fall_type3_redodt_type3_dt: ";
$end   = new DateTime('2010-11-07 00:10:20');  // dt, zt3
$start = new DateTime('2010-11-07 01:12:33 EDT');  // redodt, zt2
$start->setTimezone(new DateTimeZone('America/New_York'));  // zt2 -> zt3
examine_diff($end, $start, 'P-0Y0M0DT1H2M13S', 0);

echo "test_time_fall_type3_redodt_type3_redodt: ";
$end   = new DateTime('2010-11-07 01:15:35 EDT');  // sp redodt, zt2
$end->setTimezone(new DateTimeZone('America/New_York'));  // zt2 -> zt3
$start = new DateTime('2010-11-07 01:12:33 EDT');  // redodt, zt2
$start->setTimezone(new DateTimeZone('America/New_York'));  // zt2 -> zt3
examine_diff($end, $start, 'P+0Y0M0DT0H3M2S', 0);

echo "test_time_fall_type3_redodt_type3_redost: ";
$end   = new DateTime('2010-11-07 01:14:44 EST');  // redost, zt2
$end->setTimezone(new DateTimeZone('America/New_York'));  // zt2 -> zt3
$start = new DateTime('2010-11-07 01:12:33 EDT');  // redodt, zt2
$start->setTimezone(new DateTimeZone('America/New_York'));  // zt2 -> zt3
examine_diff($end, $start, 'P+0Y0M0DT1H2M11S', 0);

echo "test_time_fall_type3_redodt_type3_st: ";
$end   = new DateTime('2010-11-07 03:16:55');  // st, zt3
$start = new DateTime('2010-11-07 01:12:33 EDT');  // redodt, zt2
$start->setTimezone(new DateTimeZone('America/New_York'));  // zt2 -> zt3
examine_diff($end, $start, 'P+0Y0M0DT3H4M22S', 0);

echo "test_time_fall_type3_redodt_type3_post: ";
$end   = new DateTime('2010-11-08 19:59:59');  // post, zt3
$start = new DateTime('2010-11-07 01:12:33 EDT');  // redodt, zt2
$start->setTimezone(new DateTimeZone('America/New_York'));  // zt2 -> zt3
examine_diff($end, $start, 'P+0Y0M1DT19H47M26S', 1);

echo "test_time_fall_type3_redost_type3_prev: ";
$end   = new DateTime('2010-11-06 18:38:28');  // prev, zt3
$start = new DateTime('2010-11-07 01:14:44 EST');  // redost, zt2
$start->setTimezone(new DateTimeZone('America/New_York'));  // zt2 -> zt3
examine_diff($end, $start, 'P-0Y0M0DT7H36M16S', 0);

echo "test_time_fall_type3_redost_type3_dt: ";
$end   = new DateTime('2010-11-07 00:10:20');  // dt, zt3
$start = new DateTime('2010-11-07 01:14:44 EST');  // redost, zt2
$start->setTimezone(new DateTimeZone('America/New_York'));  // zt2 -> zt3
examine_diff($end, $start, 'P-0Y0M0DT2H4M24S', 0);

echo "test_time_fall_type3_redost_type3_redodt: ";
$end   = new DateTime('2010-11-07 01:12:33 EDT');  // redodt, zt2
$end->setTimezone(new DateTimeZone('America/New_York'));  // zt2 -> zt3
$start = new DateTime('2010-11-07 01:14:44 EST');  // redost, zt2
$start->setTimezone(new DateTimeZone('America/New_York'));  // zt2 -> zt3
examine_diff($end, $start, 'P-0Y0M0DT1H2M11S', 0);

echo "test_time_fall_type3_redost_type3_redost: ";
$end   = new DateTime('2010-11-07 01:16:54 EST');  // sp redodt, zt2
$end->setTimezone(new DateTimeZone('America/New_York'));  // zt2 -> zt3
$start = new DateTime('2010-11-07 01:14:44 EST');  // redost, zt2
$start->setTimezone(new DateTimeZone('America/New_York'));  // zt2 -> zt3
examine_diff($end, $start, 'P+0Y0M0DT0H2M10S', 0);

echo "test_time_fall_type3_redost_type3_st: ";
$end   = new DateTime('2010-11-07 03:16:55');  // st, zt3
$start = new DateTime('2010-11-07 01:14:44 EST');  // redost, zt2
$start->setTimezone(new DateTimeZone('America/New_York'));  // zt2 -> zt3
examine_diff($end, $start, 'P+0Y0M0DT2H2M11S', 0);

echo "test_time_fall_type3_redost_type3_post: ";
$end   = new DateTime('2010-11-08 19:59:59');  // post, zt3
$start = new DateTime('2010-11-07 01:14:44 EST');  // redost, zt2
$start->setTimezone(new DateTimeZone('America/New_York'));  // zt2 -> zt3
examine_diff($end, $start, 'P+0Y0M1DT18H45M15S', 1);

echo "test_time_fall_type3_st_type3_prev: ";
$end   = new DateTime('2010-11-06 18:38:28');  // prev, zt3
$start = new DateTime('2010-11-07 03:16:55');  // st, zt3
examine_diff($end, $start, 'P-0Y0M0DT9H38M27S', 0);

echo "test_time_fall_type3_st_type3_dt: ";
$end   = new DateTime('2010-11-07 00:10:20');  // dt, zt3
$start = new DateTime('2010-11-07 03:16:55');  // st, zt3
examine_diff($end, $start, 'P-0Y0M0DT4H6M35S', 0);

echo "test_time_fall_type3_st_type3_redodt: ";
$end   = new DateTime('2010-11-07 01:12:33 EDT');  // redodt, zt2
$end->setTimezone(new DateTimeZone('America/New_York'));  // zt2 -> zt3
$start = new DateTime('2010-11-07 03:16:55');  // st, zt3
examine_diff($end, $start, 'P-0Y0M0DT3H4M22S', 0);

echo "test_time_fall_type3_st_type3_redost: ";
$end   = new DateTime('2010-11-07 01:14:44 EST');  // redost, zt2
$end->setTimezone(new DateTimeZone('America/New_York'));  // zt2 -> zt3
$start = new DateTime('2010-11-07 03:16:55');  // st, zt3
examine_diff($end, $start, 'P-0Y0M0DT2H2M11S', 0);

echo "test_time_fall_type3_st_type3_st: ";
$end   = new DateTime('2010-11-07 05:19:56');  // sp st, zt3
$start = new DateTime('2010-11-07 03:16:55');  // st, zt3
examine_diff($end, $start, 'P+0Y0M0DT2H3M1S', 0);

echo "test_time_fall_type3_st_type3_post: ";
$end   = new DateTime('2010-11-08 19:59:59');  // post, zt3
$start = new DateTime('2010-11-07 03:16:55');  // st, zt3
examine_diff($end, $start, 'P+0Y0M1DT16H43M4S', 1);

echo "test_time_fall_type3_post_type3_prev: ";
$end   = new DateTime('2010-11-06 18:38:28');  // prev, zt3
$start = new DateTime('2010-11-08 19:59:59');  // post, zt3
examine_diff($end, $start, 'P-0Y0M2DT1H21M31S', 2);

echo "test_time_fall_type3_post_type3_dt: ";
$end   = new DateTime('2010-11-07 00:10:20');  // dt, zt3
$start = new DateTime('2010-11-08 19:59:59');  // post, zt3
examine_diff($end, $start, 'P-0Y0M1DT20H49M39S', 1);

echo "test_time_fall_type3_post_type3_redodt: ";
$end   = new DateTime('2010-11-07 01:12:33 EDT');  // redodt, zt2
$end->setTimezone(new DateTimeZone('America/New_York'));  // zt2 -> zt3
$start = new DateTime('2010-11-08 19:59:59');  // post, zt3
examine_diff($end, $start, 'P-0Y0M1DT19H47M26S', 1);

echo "test_time_fall_type3_post_type3_redost: ";
$end   = new DateTime('2010-11-07 01:14:44 EST');  // redost, zt2
$end->setTimezone(new DateTimeZone('America/New_York'));  // zt2 -> zt3
$start = new DateTime('2010-11-08 19:59:59');  // post, zt3
examine_diff($end, $start, 'P-0Y0M1DT18H45M15S', 1);

echo "test_time_fall_type3_post_type3_st: ";
$end   = new DateTime('2010-11-07 03:16:55');  // st, zt3
$start = new DateTime('2010-11-08 19:59:59');  // post, zt3
examine_diff($end, $start, 'P-0Y0M1DT16H43M4S', 1);

echo "test_time_fall_type3_post_type3_post: ";
$end   = new DateTime('2010-11-08 19:59:59');  // post, zt3
$start = new DateTime('2010-11-08 18:57:55');  // sp post, zt3
examine_diff($end, $start, 'P+0Y0M0DT1H2M4S', 0);