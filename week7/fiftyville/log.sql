-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Description of the crime
SELECT "description" FROM "crime_scene_reports"
WHERE "month" = 7 AND "day" = 28 AND "street" = "Humphrey Street";


-- Crime took place at 10:15am at the Humphrey Street bakery. Three witnesses who were present at the time – each of their interview transcripts mentions the bakery.
SELECT "transcript" FROM "interviews"
WHERE "month" = 7 AND "day" = 28 AND "transcript" LIKE '%bakery%';
-- A car exit from parking lot at 10am time frame
-- The theif withdraw money from an ATM on Leggett Street
-- As the thief leaving the bakery, they called someone , the call last for less than a minute.
-- The theif planning to take the earliest flight out of Fiftyvlille on July 29 (the day after the crime)
-- Ask the person on the other phoneline to book a flight for them


-- See what car exit the bakery at that 10am time frame
SELECT "license_plate" FROM "bakery_security_logs"
WHERE "month" = 7 AND "day" = 28 AND "hour" = 10 AND "minute" LIKE '1_' AND "activity" = "exit";


-- See what person associate with each of those cars that exit at 10am time frame
SELECT "people"."id" FROM "bakery_security_logs"
JOIN "people" ON "people"."license_plate" = "bakery_security_logs"."license_plate"
WHERE  "bakery_security_logs"."month" = 7 AND "bakery_security_logs"."day" = 28 AND "bakery_security_logs"."hour" = 10 AND "bakery_security_logs"."minute" LIKE '1_'
AND "bakery_security_logs"."activity" = "exit"
ORDER BY "bakery_security_logs"."minute";


-- See who are those people that make the phone calls that day, and the duration is less than a minute
SELECT "people"."id" FROM "phone_calls"
JOIN "people" ON "people"."phone_number" = "phone_calls"."caller"
WHERE "phone_calls"."month" = 7 AND "phone_calls"."day" = 28 AND "phone_calls"."duration" < 60;


-- See who are the people that withdraw money from an ATM on Leggett Street on July 28
SELECT DISTINCT("people"."id") FROM "bank_accounts"
JOIN "atm_transactions" ON "atm_transactions"."account_number" = "bank_accounts"."account_number"
JOIN "people" ON "people"."id" = "bank_accounts"."person_id"
WHERE "atm_transactions"."month" = 7 AND "atm_transactions"."day" = 28 AND "atm_transactions"."transaction_type" = "withdraw" AND "atm_transactions"."atm_location" = "Leggett Street";


-- Table of suspects
CREATE TABLE "suspects" (
    "person_id" INTEGER,
    PRIMARY KEY("person_id")
);

INSERT INTO "suspects" ("person_id")
SELECT "people"."id"FROM "bakery_security_logs"
JOIN "people" ON "people"."license_plate" = "bakery_security_logs"."license_plate"
WHERE "bakery_security_logs"."month" = 7 AND "bakery_security_logs"."day" = 28 AND "bakery_security_logs"."hour" = 10

INTERSECT

SELECT "people"."id" FROM "phone_calls"
JOIN "people" ON "people"."phone_number" = "phone_calls"."caller"
WHERE "phone_calls"."month" = 7 AND "phone_calls"."day" = 28 AND "phone_calls"."duration" < 60

INTERSECT

SELECT DISTINCT("people"."id") FROM "bank_accounts"
JOIN "atm_transactions" ON "atm_transactions"."account_number" = "bank_accounts"."account_number"
JOIN "people" ON "people"."id" = "bank_accounts"."person_id"
WHERE "atm_transactions"."month" = 7 AND "atm_transactions"."day" = 28 AND "atm_transactions"."transaction_type" = "withdraw" AND "atm_transactions"."atm_location" = "Leggett Street";


-- The name of the theift
SELECT "name" FROM "people"
WHERE "id" = (SELECT "person_id" FROM "suspects");


-- City that the theif escaped to
SELECT "city" FROM "airports"
WHERE "id" = (SELECT "flights"."destination_airport_id" FROM "flights"
                JOIN "airports" ON "airports"."id" = "flights"."origin_airport_id"
                WHERE "flights"."month" = 7 AND "flights"."day" = 29 AND  "airports"."city" = "Fiftyville"
                ORDER BY "flights"."hour", "flights"."minute"
                LIMIT 1);

-- The thief's helper
SELECT "name" FROM "people"
WHERE "phone_number" IN (SELECT "phone_calls"."receiver" FROM "suspects"
                        JOIN "people"  ON "people"."id" = "suspects"."person_id"
                        JOIN "phone_calls" ON  "phone_calls"."caller" = "people"."phone_number"
                        WHERE "people"."id" = "suspects"."person_id" AND  "phone_calls"."month" = 7 AND "phone_calls"."day" = 28 AND "phone_calls"."duration" < 60);
