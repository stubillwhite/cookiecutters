(ns {{cookiecutter.main_ns}}.core-test
  (:require
    [clojure.test :refer :all]
    [{{cookiecutter.main_ns}}.core :refer :all]))

(deftest add-one-given-value-then-increments []
  (is (= 24 (add-one 23))))

