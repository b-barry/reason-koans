open Helpers;

let koans = (_) =>
  Mocha.describe(
    "Literals",
    (_) => {
      Mocha.it("strings are enclosed in double quotes", (_) => Mocha.eq("string", todo()));
      Mocha.it("characters are enclosed in single quotes", (_) => Mocha.eq('a', todo()));
      Mocha.it("floats have a decimal", (_) => Mocha.eq(1.0, todo()));
      Mocha.it("integers do not", (_) => Mocha.eq(1, todo()));
      Mocha.it("floats can be negative", (_) => Mocha.eq((-1.0), todo()));
      Mocha.it("integers can be negative", (_) => Mocha.eq((-1), todo()))
    }
  );
