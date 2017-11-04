open Helpers;

open Containers;

module IMap =
  Map.Make(
    {
      type t = int;
      let compare = compare;
    }
  );

let koans = (_) =>
  Mocha.describe("Mapionaries") @@
  (
    (_) => {
      Mocha.it("Map.Make is a module functor that takes a module") @@
      (
        (_) => {
          module StringMap = Map.Make(String);
          Mocha.ok(true)
        }
      );
      Mocha.it("Map.Make takes any module with { type: t, compare: t => t => int }") @@
      (
        (_) => {
          module FloatMap = Map.Make(Float);
          Mocha.ok(true)
        }
      );
      Mocha.it(
        "Map.Make can take an arbitrary module to wrap types without a predefined OrderedType interface"
      ) @@
      (
        (_) => {
          module IntMap =
            Map.Make(
              {
                type t = int;
                let compare = compare;
              }
            );
          Mocha.ok(true)
        }
      );
      Mocha.it("Maps can be created empty") @@
      ((_) => todo() |> IMap.equal((==), IMap.empty) |> Mocha.ok);
      Mocha.it("Maps can be initialised with a single key value pair") @@
      ((_) => todo() |> IMap.equal((==), IMap.singleton(1, "value")) |> Mocha.ok);
      Mocha.it("or from a list of key-value pairs") @@
      ((_) => IMap.fromList(todo()) |> IMap.size |> Mocha.eq(2));
      Mocha.it("they can also be converted back to a list") @@
      (
        (_) =>
          todo()
          |> List.equal((==), IMap.toList @@ IMap.fromList([(1, "a"), (2, "b")]))
          |> Mocha.ok
      );
      Mocha.it("checking for an empty dictionary is easy") @@
      ((_) => todo() |> IMap.isEmpty |> Mocha.ok);
      Mocha.it("you can also check if a key is present in the dictionary") @@
      ((_) => todo() |> ((key) => IMap.mem(key, IMap.singleton(1, "a")) |> Mocha.ok));
      Mocha.it("or get the value associated with the key") @@
      ((_) => Some(todo()) |> Mocha.eq(IMap.get(1) @@ IMap.singleton(1, "a")));
      Mocha.it("a key-value pair can be added to the dictionary") @@
      ((_) => Some(todo()) |> Mocha.eq(IMap.get(2) @@ IMap.add(2, "b") @@ IMap.singleton(1, "a")));
      Mocha.it("inserting can also overwrite the value associated with a key") @@
      ((_) => Some(todo()) |> Mocha.eq(IMap.get(1) @@ IMap.add(1, "b") @@ IMap.singleton(1, "a")));
      Mocha.it("updating a value works similarly") @@
      (
        (_) =>
          Some(todo())
          |> Mocha.eq(IMap.get(1) @@ IMap.update(1, (_) => Some("b")) @@ IMap.singleton(1, "a"))
      );
      Mocha.it("but knows about the current value") @@
      (
        (_) =>
          Some(todo())
          |> Mocha.eq(
               IMap.get(1) @@
               IMap.update(1, (v) => Some(Option.get("", v) ++ "b")) @@
               IMap.singleton(1, "a")
             )
      );
      Mocha.it("updating can add a new value") @@
      (
        (_) =>
          Some(todo())
          |> Mocha.eq(IMap.get(2) @@ IMap.update(2, (_) => Some("b")) @@ IMap.singleton(1, "a"))
      );
      Mocha.it("or even remove a value") @@
      (
        (_) =>
          Some(todo())
          |> Mocha.eq(IMap.get(1) @@ IMap.update(1, (_) => None) @@ IMap.singleton(1, "a"))
      );
      Mocha.it("of course there is a more direct way to remove a value too") @@
      ((_) => Some(todo()) |> Mocha.eq(IMap.get(1) @@ IMap.remove(1) @@ IMap.singleton(1, "a")));
      Mocha.it("you can get the list of keys") @@
      ((_) => todo() |> Mocha.eq(IMap.keysList @@ IMap.singleton(1, "a")));
      Mocha.it("or the list of values") @@
      ((_) => todo() |> Mocha.eq(IMap.valuesList @@ IMap.singleton(1, "a")));
      Mocha.it("mapping works similarly as with lists") @@
      (
        (_) =>
          todo()
          |> Mocha.eq(
               IMap.valuesList @@ IMap.map((_, v) => v ++ "c", IMap.fromList([(1, "a"), (2, "b")]))
             )
      )
    }
  );
