<script>
  import * as mathlive from 'mathlive'
  export let value;
  import { beforeUpdate } from 'svelte';
  let mf;
  beforeUpdate(() => {
    if (mf !== undefined) {
      mf.setValue(value);
    }
  });
</script>

<math-field bind:this="{mf}" readonly></math-field>
